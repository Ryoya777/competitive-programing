#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>
#include <random>
#include <time.h>
#include <cfloat>
#include <cmath>
class gauss
{
public:
    gauss(std::int32_t Number_of_Rows, std::int32_t Number_of_Cols);

    void solve();

    void see_elements();

private:
    using col_vec = std::vector<double>;
    col_vec ans;

    std::vector<col_vec> matrix;

    int32_t number_of_rows, number_of_cols;
};

gauss::gauss(int32_t Number_of_Rows, int32_t Number_of_Cols) : number_of_rows(Number_of_Rows), number_of_cols(Number_of_Cols), ans(Number_of_Rows, 0), matrix(Number_of_Cols, std::vector<double>(Number_of_Rows, 0.0))
{
    std::mt19937 engine((int32_t)time(NULL));
    for (auto &column : matrix)
    {
        for (auto &ele : column)
        {
            double res = engine() % 1000;
            ele = res;
        }
    }
}

void gauss::see_elements()
{
    std::cout << "row:" << number_of_rows << "number_of_cols:" << number_of_cols << "\n";
    for (int32_t i = 0; i < number_of_rows; ++i)
    {
        std::cout << "| ";
        for (int32_t j = 0; j < number_of_cols; ++j)
        {
            std::cout << matrix[j][i];
            std::cout << " ";
        }
        std::cout << "|\n";
    }
}

void gauss::solve()
{
    int32_t num_of_row = 0;
    int32_t num_of_col = 0;
    for (int32_t now_col = 0; now_col < number_of_cols; now_col++)
    {
        for (int32_t del_row = 0; del_row < number_of_rows; del_row++)
        {
            //0除算回避
            if (std::fabs(matrix[now_col][del_row]) < DBL_MIN)
            {
                continue;
            }
            else
            {
                double div = matrix[now_col][del_row];
                for (int32_t div_col = now_col; div_col < number_of_cols; div_col++)
                {
                    for (int32_t div_row = del_row; div_row < number_of_rows; div_row++)
                    {
                        
                    }
                }
            }
        }
    }
}

int32_t main()
{
    gauss mamama(3, 2);
    mamama.see_elements();
    return 0;
}