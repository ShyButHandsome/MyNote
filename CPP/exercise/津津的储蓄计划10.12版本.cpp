#include<iostream>
#include<cmath>

using namespace std;

const int ADD = 300;

int cost[12] = {0};

int mother[12] = {0};
//judge JJ should eat mud or not
double judge = 0;
//how much money JJ rest
double rest = 0;
//how much money JJ finally get
double get = 0;

int main(void)
{
    cout << "Enter cost:";
    for (int a = 0; a < 12; a++)
    {
        //enter data
        cin >> cost[a];
    }

    
    for (int i = 0; i < 12; i++)
    {
        //use 'if' to check data
        if (cost[i] <= 350 && cost[i] > 0)
        {
            //use 'if' to judge if JJ give money to mother
            if ((rest + (ADD - cost[i])) >= 0)
            {
                mother[i] = (rest + (ADD - cost[i])) / 100;
                mother[i] *= 100;
            }
            else
            {
                //Don't give
                mother[i] = 0;
            }
            //how much JJ rest
            rest -= mother[i];
            rest += (ADD - cost[i]);
            //use 'if' to judge
            judge = rest;
            //if JJ should eat mud
            if (judge < 0)
            {
                //which month JJ should eat mud
                int MudMonth = i + 1;
                cout << MudMonth * -1;
                break;
            }
            //if JJ needn't eat mud
            //go around
        }
        else
        {
            //Wrrong data
            cout << "Enter Wrrong!";
            //let me know
            return -1;
        }
    }
    //mother give
    for (int k = 0; k < 12; k++)
    {
        get += mother[k];
    }
    get = 1.2 * get;
    //add rest
    get += rest;
    //putout how much get
    cout << get;
    return 0;
}
