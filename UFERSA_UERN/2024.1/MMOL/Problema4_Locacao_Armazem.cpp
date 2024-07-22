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
    // d: customer demand
    // f: warehouse operating cost
    IloArray<IloNumArray> c(env);
    IloNumArray d(env);
    IloNumArray f(env);
    file >> c;
    file >> d;
    file >> f;
    IloInt n = d.getSize();
    IloInt m = f.getSize();

    // Set the decision variables.
    // x: quantity of shipped products
    IloArray<IloNumVarArray> x(env, m);
    for (IloInt i = 0; i < m; i++)
    {
      x[i] = IloNumVarArray(env, n, 0, IloInfinity, ILOINT);
    }
    // y: warehouse is open or not
    IloNumVarArray y(env, m, 0, 1, ILOBOOL);

    // Set the model.
    IloModel model(env);

    // Set the objective function.
    // minimize sum_{i=1}^m sum_{j=1}^n c_{ij} * x_{ij} + sum_{i=1}^m f_i * y_i
    // sum_{i=1}^m sum_{j=1}^n c_{ij} * x_{ij}
    IloExpr objective_function(env);
    for (IloInt i = 0; i < m; i++)
    {
      for (IloInt j = 0; j < n; j++)
      {
        objective_function += c[i][j] * x[i][j];
      }
    }
    // sum_{i=1}^m f_i * y_i
    for (IloInt i = 0; i < m; i++)
    {
      objective_function += f[i] * y[i];
    }
    model.add(IloMinimize(env, objective_function));
    objective_function.end();

    // Set the constraints.
    // sum_{i=1}^m x_{ij} = d_j, forall j = 1 ... n
    for (IloInt j = 0; j < n; j++)
    {
      IloExpr constraint(env);
      for (IloInt i = 0; i < m; i++)
      {
        constraint += x[i][j];
      }
      model.add(constraint == d[j]);
      constraint.end();
    }
    // sum_{j=1}^n x_{ij} - y_i * (sum_{j=1}^n dj) <= 0, forall i = 1 ... m
    // sum_{j=1}^n dj
    IloExpr sum_d(env);
    for (IloInt j = 0; j < n; j++)
    {
      sum_d += d[j];
    }
    // sum_{j=1}^n x_{ij} - y_i * sum_d <= 0, forall i = 1 ... m
    for (IloInt i = 0; i < m; i++)
    {
      IloExpr sum_x(env);
      for (IloInt j = 0; j < n; j++)
      {
        sum_x += x[i][j];
      }
      model.add((sum_x - y[i] * sum_d) <= 0);
      sum_x.end();
    }
    sum_d.end();

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
    for (IloInt i = 0; i < m; i++)
    {
      cout << "y[" << i << "] = " << cplex.getValue(y[i]) << endl;
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
