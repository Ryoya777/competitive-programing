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
    gauss(std::int32_t Row, std::int32_t Col);

    void solve();

    void see_elements();

private:
    using col_vec = std::vector<double>; 
    col_vec ans;

    std::vector<std::vector<double>> matrix;

    int32_t row, col;
};

gauss::gauss(int32_t Row, int32_t Col) : row(Row), col(Col), ans(Row, 0), matrix(Col, std::vector<double>(Row, 0.0))
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
    std::cout << "row:" << row << "col:" << col << "\n";
    for (int32_t i = 0; i < row; ++i)
    {
        std::cout << "| ";
        for (int32_t j = 0; j < col; ++j)
        {
            std::cout << matrix[i][j];
            std::cout << " ";
        }
        std::cout << "|\n";
    }
}

void gauss::solve()
{
    int32_t num_of_row = 0;
    int32_t num_of_col = 0;
    for (int32_t now_col = 0; now_col < col; now_col++)
    {
        for (int32_t del_row = 0; del_row < row; del_row++)
        {
            //0除算回避
            if(std::fabs(matrix[now_col][del_row]) < DBL_MIN){
                continue;
            }
            else{
                double div = matrix[now_col][del_row];
                for(int32_t div_col = now_col;div_col < col;div_col++){
                    for(int32_t div_row = del_row; div_row < row;div_row++){
                        
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