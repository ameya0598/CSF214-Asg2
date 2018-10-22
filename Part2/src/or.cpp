#include "or.h"
#include "helpers.h"

using namespace std;

bool or_introduction_check(vector<string> &tr, string in, int l1, int l2, vector<string>& v)
{
    string temp = string_separate(in), pf_temp, pf_sub;
    
    // int l1 = (in[pos] - '0'), l2 = (in[pos + 2] - '0') - 1;
    /*l1 is type of elimination and l2 is line number of the and statement*/

    stack<char> check;
    string temp_input = v[l2];
    string sub = string_separate(temp_input);
    
    generate(temp, pf_temp);
    generate(sub, pf_sub);

    string left, right;

    check.push('(');
    if (l1 == 1)
    {
        for (int i = 0; i < temp.length(); i++)
        {
            left.push_back(temp[i]);

            if (temp[i] == '(')
                check.push(temp[i]);
            else if (temp[i] == ')')
                check.pop();

            if (check.size() == 1 && temp[i + 1] == 'V')
            {
                string pf_left;
                generate(left, pf_left);

                if (pf_left == pf_sub)
                {
                    tr.push_back(pf_temp);
                    return true;
                }
            }
        }
    }
    else if (l1 == 2)
    {
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == '(')
                check.push(temp[i]);
            else if (temp[i] == ')')
                check.pop();

            if (check.size() == 1 && temp[i + 1] == 'V')
            {
                for (int j = i + 2; j < temp.length(); j++)
                    right.push_back(temp[j]);

                string pf_right;
                generate(right, pf_right);

                if (pf_right == pf_sub)
                {
                    tr.push_back(pf_temp);
                    return true;
                }
            }
        }
    }

    return false;
}