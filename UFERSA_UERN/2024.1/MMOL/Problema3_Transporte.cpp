#include <ilcplex/ilocplex.h>
#include <fstream>

ILOSTLBEGIN

int main()
{
  IloEnv env;

  try
  {
    // Get data from file.
    string filename = "my_file.dat";
    cout << "Reading file: " << filename << endl
         << endl;
    ifstream file(filename.c_str());
    if (!file)
    {
      cerr << "No such file: " << filename << endl
           << endl;
      throw(1);
    }

    // Set the problem parameters.
    // c: shipping cost
    // b: city demand
    // a: factory production capacity
    IloArray<IloNumArray> c(env);
    IloNumArray b(env);
    IloNumArray a(env);
    file >> c;
    file >> b;
    file >> a;
    IloInt n = b.getSize();
    IloInt m = a.getSize();

    // Set the decision variable.
    // x: quantity of shipped products
    IloArray<IloNumVarArray> x(env, m);
    for (IloInt i = 0; i < m; i++)
    {
      x[i] = IloNumVarArray(env, n, 0, IloInfinity, ILOINT);
    }

    // Set the model.
    IloModel model(env);

    // Set the objective function.
    // minimize sum_{i=1}^m sum_{j=1}^n c_{ij} * x_{ij}
    IloExpr objective_function(env);
    for (IloInt i = 0; i < m; i++)
    {
      for (IloInt j = 0; j < n; j++)
      {
        objective_function += c[i][j] * x[i][j];
      }
    }
    model.add(IloMinimize(env, objective_function));
    objective_function.end();

    // Set the constraints.
    // sum_{j=1}^n x_{ij} <= a_i, forall i = 1 ... m
    for (IloInt i = 0; i < m; i++)
    {
      IloExpr constraint(env);
      for (IloInt j = 0; j < n; j++)
      {
        constraint += x[i][j];
      }
      model.add(constraint <= a[i]);
      constraint.end();
    }
    // sum_{i=1}^m x_{ij} >= bj, forall j = 1 ... n
    for (IloInt j = 0; j < n; j++)
    {
      IloExpr constraint(env);
      for (IloInt i = 0; i < m; i++)
      {
        constraint += x[i][j];
      }
      model.add(constraint >= b[j]);
      constraint.end();
    }

    // Solve the model.
    IloCplex cplex(model);
    if (cplex.solve())
    {
      cout << endl
           << "Solution status: " << cplex.getStatus() << endl;
      cout << "Optimal value = " << cplex.getObjValue() << endl
           << endl;
    }
    else
    {
      cout << "Solving error" << endl;
    }

    // Export results into files.
    cplex.exportModel("result.lp");
    cplex.writeSolution("result.txt");

    // Show the results.
    cout << endl;
    for (IloInt i = 0; i < m; i++)
    {
      for (IloInt j = 0; j < n; j++)
      {
        cout << "x[" << i << "][" << j << "] = " << cplex.getValue(x[i][j]) << endl;
      }
    }
    cout << endl;
  }
  catch (IloException &e)
  {
    cerr << "Error: " << e << endl;
  }
  catch (...)
  {
    cerr << "Unknown error" << endl;
  }

  env.end();

  return 0;
}
