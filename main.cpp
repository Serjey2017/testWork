#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;

char *test_string;
typedef std::vector<int> IVec;

int powInt(int x, int y)
{
    for (int i = 0; i < y; i++)
    {
        x *= 10;
    }
    return x;
}

bool _is_number(char &data){
    int n = data - '0';
    if( (n>0) && n <('9'-'0') )
        return true;
    return false;
}

bool _is_sign(char &data){
    if('-' == data)
        return true;
    return false;
}

bool convertToInt(char* str, int &sum){
    int len = strlen(str);
    int exp = 0;
    for (int x = 0; x < len; x++)
    {
        int n = str[x] - '0';
        if( (n>0) && n <('9'-'0') )
            exp++;
    }


    for (int x = 0; x < len; x++)
    {
        int c = (str[x] - '0');
        if( (c>0) && c <('9'-'0') )
        {
            exp--;
            sum = sum + c*pow(10, (exp) );
        }
    }
    return true;
}

int ParseInt(char* input)
{
    int sum = 0;
    int len = strlen(input);
    bool _find_number = false;
    char tmpval[255];
    char tmpsign = ' ';
    bool _have_sign = false;
    for (int x = 0; x < len; x++)
    {
        char tmp = input[x];
        if(_is_number(tmp))
        {
            strcat(tmpval, &tmp);
            _find_number = true;
            _have_sign = _is_sign(tmpsign);
        }
        else
        {
            if(_find_number)
                break;
        }
        tmpsign = tmp;
    }

    convertToInt(tmpval,sum);
    if(_have_sign)
        sum = sum*(-1);

    return sum;
}

void print2dVec(vector<vector<int> > k){

    for(unsigned int i = 0; i < k.size(); ++i){
        for(unsigned int j = 0; j < k[i].size(); ++j)
            cout << k[i][j] << " ";

        cout << endl;
    }
    cout << endl << endl;

}

void mat_initializer(vector<vector<int>> &vec, int m, int n){

    int k(0);
    for (int i=0;i<n;++i){
        vec.push_back(vector<int>());
        for(int j=0;j<m;++j){
            k++;
            vec[i].push_back(k);// = k;
        }}
    cout<<"matrix "<<m<<"x"<<n<<" was init"<<endl;
    print2dVec(vec);
}

int Spiral(vector<vector<int>> &input){
    if( !(input.size()>0) || !(input.at(0).size()>0) )
    {
        cout<<"can't take that"<<endl;
        return 0;
    }
    cout<<"spiral: ";
while( (input.size()>0) && (input.at(0).size() > 0) )
{

    for(uint t = 0; t<input.at(0).size(); t++){
        cout<<" "<< input.at(0).at(t);
    }
{ //delete 1 row
        vector<vector<int> >::iterator row = input.begin();
        row->clear();// Clear out that row
        input.erase(row);// Remove that row
}

    std::vector<IVec> temp(input[0].size(), IVec(input.size()));

        int count = 0;
        int count2 = 0;

        for( count = 0; count < input.size(); count++ )
        {
            for( count2 = 0; count2 < input[0].size(); count2++ )
            {
                temp[temp.size()-count2-1][count] = input[count][count2];
            }
        }
        input = temp;
}
    cout<<endl;
      return 1;
}

int main(int argc, char* argv[])
{
    vector<vector<int> > mat;
    //mat_initializer(mat, 3, 3);
    test_string = "sdfhjgjhfg1234jgsd64f";



    //Spiral(mat);


 cout<<" parse some char int = " << ParseInt(test_string) << endl;

//print2dVec(mat);
    return 0;
}
