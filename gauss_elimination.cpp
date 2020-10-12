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
    using row_vec = std::vector<double>;
    col_vec ans;

    std::vector<row_vec> matrix;

    int32_t number_of_rows, number_of_cols;
    void pivot_select(int start);
};

gauss::gauss(int32_t Number_of_Rows, int32_t Number_of_Cols) : number_of_rows(Number_of_Rows), number_of_cols(Number_of_Cols), ans(Number_of_Cols - 1, 1), matrix(Number_of_Rows, row_vec(Number_of_Cols, 0.0))
{
    std::mt19937 engine((int32_t)time(NULL));
    for (auto &column : matrix)
    {
        for (auto &ele : column)
        {
            double res = engine() % 100;
            ele = res;
        }
    }
}

void gauss::pivot_select(int start)
{
    //ゼロ含む時に枢軸にしないだけ
    for (int32_t i = start; i < number_of_rows; ++i)
    {
        bool zero_exist = false;
        for (auto &gyou : matrix[i])
        {
            //0除算回避
            if (gyou < 1e-10)
            {
                zero_exist = true;
            }
        }
        if (zero_exist)
        {
        }
        else
        {
            swap(matrix[start], matrix[i]);

            return;
        }
    }
}

void gauss::see_elements()
{
    //std::cout << "row:" << number_of_rows << "number_of_cols:" << number_of_cols << "\n";
    for (int32_t i = 0; i < number_of_rows; ++i)
    {
        std::cout << " ";
        for (int32_t j = 0; j < number_of_cols; ++j)
        {
            std::cout << matrix[i][j];
            std::cout << " ";
        }
        std::cout << "|\n";
    }
}

void gauss::solve()
{
    int32_t shallow_roop = 0;
    pivot_select(0);
    //階段形まで
    for (shallow_roop = 0; shallow_roop < number_of_cols - 2; shallow_roop++)
    {
        for (int32_t now_col = shallow_roop + 1; now_col < number_of_rows; now_col++)
        {
            double coefficient = (matrix[now_col][shallow_roop] / matrix[shallow_roop][shallow_roop]);
            //std::cout << "coefficient" << coefficient << "\n";
            for (int32_t now_row = shallow_roop; now_row < number_of_cols; now_row++)
            {
                matrix[now_col][now_row] -= coefficient * matrix[shallow_roop][now_row];
                this->see_elements();
                std::cout << "now_col " << now_col << " now_row" << now_row << "\n\n";
            }
            //std::cout << "out!!\n";
        }
    }
    this->see_elements();
    //後退代入
    //ここはnow_colとnow_rowの使い方が変数の意味と完全に逆になっている。
    int32_t times = 1;
    for (int32_t now_col = number_of_rows - 1; now_col >= 0; now_col--)
    {
        double total_of_left = 0;
        for (int32_t i = 1; i < times; i++)
        {
            total_of_left -= matrix[now_col][number_of_cols - i - 1] * ans[number_of_cols - i - 1];
            //std::cout << matrix[now_col][number_of_cols-i-1] <<"*"<< ans[number_of_cols-i-1] << "\n";
        }
        total_of_left += matrix[now_col][number_of_cols - 1];
        ans[now_col] = total_of_left / matrix[now_col][now_col];
        times++;
    }
    std::cout << "\n";
    int32_t cnt = 1;
    for (auto &x : ans)
    {
        std::cout << "X" << cnt << "=" << x << std::endl;
        cnt++;
    }
}

int32_t main()
{
    gauss mamama(3, 4);
    mamama.see_elements();
    std::cout << "\n";
    mamama.solve();
    mamama.see_elements();
    return 0;
}