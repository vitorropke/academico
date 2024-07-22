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
    // c: product profit
    // b: available material
    // a: quantity of material used in the product
    IloNumArray c(env);
    IloNumArray b(env);
    IloArray<IloNumArray> a(env);
    file >> c;
    file >> b;
    file >> a;
    IloInt n = c.getSize();
    IloInt m = a.getSize();

    // Set the decision variable.
    // x: quantity produced of the product
    IloNumVarArray x(env, n, 0, IloInfinity, ILOINT);

    // Set the model.
    IloModel model(env);

    // Set the objective function.
    // maximize sum_{j=1}^n c_j * x_j
    IloExpr objective_function(env);
    for (IloInt j = 0; j < n; j++)
    {
      objective_function += c[j] * x[j];
    }
    model.add(IloMaximize(env, objective_function));
    objective_function.end();

    // Set the constraints.
    // sum_{j=1}^n a_{ij} * x_j <= b_i, forall i = 1 ... m
    for (IloInt i = 0; i < m; i++)
    {
      IloExpr constraint(env);
      for (IloInt j = 0; j < n; j++)
      {
        constraint += a[i][j] * x[j];
      }
      model.add(constraint <= b[i]);
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
    for (IloInt j = 0; j < n; j++)
    {
      cout << "x[" << j << "] = " << cplex.getValue(x[j]) << endl;
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
