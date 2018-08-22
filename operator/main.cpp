#include <iostream>

using namespace std;

class IntMatrix
{
public:
    IntMatrix();//default constructor
    IntMatrix(int n);//constructor with a parameter
    IntMatrix(int r,int c);
    IntMatrix(const IntMatrix& m);
    ~IntMatrix();//destructor
    friend ostream &operator<<(ostream &,IntMatrix &);//operator << overloading
    friend istream &operator>>(istream &,IntMatrix &);//operator >> overloading
    IntMatrix & operator + (const IntMatrix & m);//operator + overloading
    IntMatrix & operator = ( IntMatrix & m);//operator = overloading
private:
    int row,column;
    int **p;//dynamic array
};

IntMatrix::IntMatrix()
{
    int i;
    p=new int * [10];//dynamic array
    for(i=0;i<10;i++)
        p[i]=new int [10];
}

IntMatrix::IntMatrix(int n)
{
    int i,j;
    row=n;
    column=n;
    p=new int * [n];//dynamic array
    for(i=0;i<n;i++)
        p[i]=new int [n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)p[i][j]=1;
            else p[i][j]=0;
        }
    }
}

IntMatrix::IntMatrix(int r,int c)
{
    int i;
    row=r;
    column=c;
    p=new int * [row];//dynamic array
    for(i=0;i<row;i++)
        p[i]=new int [column];
}

IntMatrix::IntMatrix(const IntMatrix& m)
{
    row=m.row;
    column=m.column;
    p=new int * [row];
    for(int i=0;i<row;i++)
    {
        p[i]=new int[column];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            p[i][j]=m.p[i][j];
        }
    }
}

IntMatrix::~IntMatrix()
{
    int i;
    for(i=0;i<row;i++)
        delete [] p[i];//delete dynamic array
    delete [] p;
}



ostream &operator<<(ostream & output,IntMatrix & m)
{
    int i,j;
    for(i=0;i<m.row;i++)
    {
        for(j=0;j<m.column;j++)
        {
            output << m.p[i][j] << " ";
        }
        output << endl;
    }
    return output;
}

istream &operator>>(istream & input,IntMatrix & m)
{
    int i,j;
    cout << "Please input the int matrix:";
    for(i=0;i<m.row;i++)
    {
        for(j=0;j<m.column;j++)
        {
            input >> m.p[i][j];
        }
    }

    return input;
}

IntMatrix & IntMatrix::operator+(const IntMatrix & m)
{
    row=m.row;
    column=m.column;
    IntMatrix *temp=new IntMatrix(row,column);
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<column;j++)
            temp->p[i][j]=this->p[i][j]+m.p[i][j];
    return *temp;
}

IntMatrix & IntMatrix::operator=( IntMatrix & m)
{
    int i,j;
    if(row!=m.row||column!=column)cout << "Error";
    else
    {
        p=new int *[m.row];//dynamic array
        for (i = 0; i < m.row; i++)
        p[i] = new int [m.column];
        for(i=0;i<m.row;i++)
        {
            for(j=0;j<m.column;j++)
            {
                p[i][j]=m.p[i][j];
            }
        }
    }
    return *this;
}

int main()
{
    int row,column,number,row1,column1,row2,column2;
    cout << "the row of IntMatrix:";
    cin >> row;
    cout << "the column of IntMatrix:";
    cin >> column;
    IntMatrix matrix(row,column);
    cin >> matrix;
    cout << matrix;
    cout << "the line of IntMatrix:";
    cin >> number;
    IntMatrix square_matrix(number,number);
    IntMatrix square(number,number);
    cin >> square_matrix;
    square=square_matrix+IntMatrix(number);
    cout << "square_matrix+IntMatrix(n)=\n" << square;
    cout << "the row of IntMatrix:";
    cin >> row1;
    cout << "the column of IntMatrix:";
    cin >> column1;
    IntMatrix square_matrix_A(row,column);
    cout << "square_matrix_A:";
    cin >> square_matrix_A;
    cout << "the row of IntMatrix:";
    cin >> row2;
    cout << "the column of IntMatrix:";
    cin >> column2;
    IntMatrix square_matrix_B(row,column);
    cout << "square_matrix_B:";
    cin >> square_matrix_B;
    square_matrix_A=square_matrix_A+square_matrix_B;
    if(row1==row2&&column1==column2)cout << "square_matrix_A+square_matrix_B=\n" << square_matrix_A;
    square_matrix_A=square_matrix_B;
    if(row1==row2&&column1==column2)cout << "square_matrix_A=square_matrix_B=\n" << square_matrix_A;
    return 0;
}
