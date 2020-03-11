#ifndef QPWRAPPERS_GUROBI_HPP
#define QPWRAPPERS_GUROBI_HPP

#include "problem.hpp"
#include "types.hpp"
#include <gurobi_c++.h>
#include <string>

namespace QPWrappers {
    namespace GUROBI {
        
        /*
            A QP engine that solves consecutive QP instances where the result of the previous
            instance used as an initial guess to the next one unless an initial guess
            is provided.
        */
        template<typename T>
        class Engine {
            public:
                Engine(): psd_tolerance(0) {
                    env.set(GRB_IntParam_OutputFlag, 0);
                    env.set(GRB_DoubleParam_FeasibilityTol, 1e-6);
                    env.set(GRB_DoubleParam_PSDTol, psd_tolerance);
                    env.start();
                }

                Engine(const Engine& rhs) = delete;
                Engine& operator=(const Engine& rhs) = delete;

                Engine(Engine&& rhs) = delete;
                Engine& operator=(Engine&& rhs) = delete;

                ~Engine() {
                }

                /*
                    By how much are the constraints allowed to be violated?
                */
                void setFeasibilityTolerance(T tolerance) {
                    env.set(GRB_DoubleParam_FeasibilityTol, tolerance);
                }

                /*
                    By how much are the eigenvalues of the Q matrix are allowed be below 0 during PSD check?
                */
                void setPSDCheckEigenvalueTolerance(T tolerance) {
                    psd_tolerance = tolerance;
                    env.set(GRB_DoubleParam_PSDTol, tolerance);
                }

                /*
                    Solve the first intance of the set of problems.
                    Load solution result to result.
                */
                OptReturnType init(const Problem<T>& problem, typename Problem<T>::Vector& result) {
                    GRBModel model{env};
                    GRBVar* vars = model.addVars(problem.lbx().data(), problem.ubx().data(), NULL, NULL, NULL, problem.num_vars());

                    for(typename Problem<T>::Index i = 0; i < problem.num_constraints(); i++) {
                        GRBLinExpr expr;
                        for(typename Problem<T>::Index j = 0; j < problem.num_vars(); j++) {
                            expr += problem.A()(i, j) * vars[j];
                        }

                        model.addConstr(expr, GRB_LESS_EQUAL, problem.ub()(i));
                        model.addConstr(expr, GRB_GREATER_EQUAL, problem.lb()(i));
                    }

                    GRBQuadExpr obj_quad{0};
                    for(typename Problem<T>::Index i = 0; i < problem.num_vars(); i++) {
                        for(typename Problem<T>::Index j = 0; j < problem.num_vars(); j++) {
                            obj_quad += problem.Q()(i, j) * vars[i] * vars[j];
                        }
                    }
                    obj_quad *= 0.5;

                    GRBLinExpr obj_lin{0};
                    for(typename Problem<T>::Index i = 0; i < problem.num_vars(); i++) {
                        obj_lin += problem.c()(i) * vars[i];
                    }

                    model.setObjective(obj_quad + obj_lin);


                    if(problem.is_Q_psd(psd_tolerance)) {
                        env.set(GRB_IntParam_Method, 0);
                    } else {
                        env.set(GRB_IntParam_Method, -1);
                    }

                    model.optimize();
                    auto status = model.get(GRB_IntAttr_Status);

                    if(status == GRB_OPTIMAL) {
                        loadResult(vars, problem.num_vars(), result);
                        delete[] vars;
                        return OptReturnType::Optimal;
                    } else if(status == GRB_INFEASIBLE) {
                        delete[] vars;
                        return OptReturnType::Infeasible;
                    } else if (status == GRB_INF_OR_UNBD) {
                        delete[] vars;
                        return OptReturnType::InfeasibleOrUnbounded;
                    } else if(status == GRB_UNBOUNDED) {
                        delete[] vars;
                        loadResult(vars, problem.num_vars(), result);
                        return OptReturnType::Unbounded;
                    } else if (status == GRB_NUMERIC) {
                        delete[] vars;
                        return OptReturnType::Error;
                    } else if (status == GRB_SUBOPTIMAL) {
                        delete[] vars;
                        loadResult(vars, problem.num_vars(), result);
                        return OptReturnType::Feasible;
                    }

                    delete[] vars;
                    return OptReturnType::Unknown;
                }

                /*
                    Solve the next problem of the set of problems.
                */
                OptReturnType next(const Problem<T>& problem, typename Problem<T>::Vector& result) {
                    return init(problem, result);
                }

                /*
                    Solve the next problem of the set of problems with the given initial guess.
                    Since there is no concept of feeding initial guess in GUROBI, we simply call init.
                */
                OptReturnType next(const Problem<T>& problem, typename Problem<T>::Vector& result, const typename Problem<T>::Vector& initial_guess) {
                    return init(problem, result);
                }

            private:
                GRBEnv env;
                T psd_tolerance;

                void loadResult(GRBVar* vars, typename Problem<T>::Index var_count, typename Problem<T>::Vector& result) {
                    result.resize(var_count);

                    for(typename Problem<T>::Index i = 0; i < var_count; i++) {
                        result(i) = vars[i].get(GRB_DoubleAttr_X);
                    }
                }
        };
    }
}

#endif
