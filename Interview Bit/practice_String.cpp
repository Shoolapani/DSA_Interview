#include <bits/stdc++.h>
using namespace std;

// 151. Reverse Words in a String
string reverseWords(string s)
{
    string ans = "", temp = "";
    bool flag = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if ((s[i] == ' '))
        {
            if (flag)
            {
                flag = 0;
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += " ";
                temp.clear();
            }
        }
        else
        {
            temp += s[i];
            flag = 1;
        }
    }

    if (flag)
    {
        flag = 0;
        reverse(temp.begin(), temp.end());
        ans += temp;
        temp.clear();
    }
    if (ans[ans.length() - 1] == ' ')
    {
        ans.pop_back();
    }

    return ans;
}

string longestCommonPrefix(vector<string> &ar)
{
    int n = ar.size();
    // If size is 0, return empty string
    if (n == 0)
        return "";

    if (n == 1)
        return ar[0];

    // Sort the given array
    sort(ar.begin(), ar.end());
    // Find the minimum length from
    // first and last string
    int en = min(ar[0].size(),
                 ar[n - 1].size());

    // Now the common prefix in first and
    // last string is the longest common prefix
    string first = ar[0], last = ar[n - 1];
    int i = 0;
    while (i < en && first[i] == last[i])
        i++;

    string pre = first.substr(0, i);
    return pre;
}

int romanToInt(string s)
{
    unordered_map<char, int> uMap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int ans = 0;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (((uMap[s[i]]) < uMap[s[i + 1]]))
        {
            ans -= uMap[s[i]];
            ans += uMap[s[i + 1]];
            ++i;
        }
        else
        {
            ans += uMap[s[i]];
        }
    }

    return ans;
}

// Integer To Roman
string intToRoman(int A)
{
    string thousands[] = {"", "M", "MM", "MMM"};
    string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    string ans = "";

    ans = thousands[A / 1000] + hundreds[(A % 1000) / 100] + tens[(A % 100) / 10] + ones[A % 10];

    return ans;
}

int myAtoi(string s)
{
    long long int ans = 0;
    int signFlag = 1, index = 0;

    for (index = 0; index < s.length() && s[index] == ' ';)
    {
        ++index;
    }

    if (s[index] == '-' || s[index] == '+')
    {
        if (s[index] == '-')
            signFlag = -1;
        index++;
    }

    for (; index < s.length() && s[index] >= '0' && s[index] <= '9'; index++)
    {
        ans = (ans * 10) + (s[index] - '0');
        if (ans * signFlag >= INT_MAX)
            return INT_MAX;
        if (ans * signFlag <= INT_MIN)
            return INT_MIN;
    }

    return ans * signFlag;
}

string prefixFind(string s1, string s2)
{
    int index = 0;
    string prefix = "";

    while (((index < s1.length()) && (index < s2.length())) && ((s1[index] == s2[index])))
    {
        prefix += s1[index];
        ++index;
    }

    return prefix;
}

string longestCommonPrefix2(vector<string> &strs)
{
    string prefix = strs[0];

    for (size_t i = 1; i < strs.size(); i++)
    {
        prefix = prefixFind(prefix, strs[i]);
    }

    return prefix;
}

// Implement strStr()
int strStr(string str, string pat)
{
    if (pat.empty())
    {
        return 0;
    }

    if (pat.length() > str.length())
    {
        return -1;
    }

    const int d = 256;
    int q = INT_MAX;
    int m = pat.size();
    long long int n = str.size();
    long long int p = 0, t = 0;
    long long int h = 1;

    for (size_t i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (size_t i = 0; i < m; i++)
    {
        p = ((d * p) + pat[i]) % q;
        t = ((d * t) + str[i]) % q;
    }

    for (size_t i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (str[i + j] != pat[j])
                {
                    break;
                }
            }

            if (j == m)
            {
                return i;
            }
        }

        if (i < n - m)
        {
            t = (d * (t - str[i] * h) + str[i + m]) % q;

            if (t < 0)
            {
                t = (t + q);
            }
        }
    }

    return -1;
}

// 38. Count and Say
string countAndSay(int n)
{
    string res = "1";

    while (--n)
    {
        string temp = "";
        for (size_t i = 0; i < res.length(); i++)
        {
            int count = 1;
            while ((i + 1 < res.length()) && (res[i] == res[i + 1]))
            {
                ++count;
            }
            temp = temp + to_string(count) + res[i];
        }
        res = temp;
    }

    return res;
}

string printSubStr(string str, int low, int high)
{
    string res = "";
    for (int i = low; i <= high; ++i)
        res += str[i];

    return res;
}

string longestPalindrome(string s)
{
    vector<vector<bool>> table(s.length(), vector<bool>(s.length(), 0));
    int n = s.length(), maxLength = 1;
    int start = 0;

    // for single
    for (size_t i = 0; i < s.length(); i++)
    {
        table[i][i] = 1;
    }

    // for maxLength 2
    for (size_t i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    // for length 3
    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            // ending index
            int k = j + i - 1;

            if ((table[j + 1][k - 1]) && (s[j] == s[k]))
            {
                table[j][k] = 1;

                if (i > maxLength)
                {
                    start = j;
                    maxLength = i;
                }
            }
        }
    }

    string res = printSubStr(s, start, start + maxLength - 1);
    return res;
}

int compareVersion(string version1, string version2)
{
    int i = 0, j = 0;

    while ((i < version1.length()) || (j < version2.length()))
    {
        int num1 = 0, num2 = 0;
        string s1, s2;
        while ((i < version1.length()) && (version1[i] != '.'))
        {
            s1 += version1[i];
            i++;
        }

        while ((j < version2.length()) && (version2[j] != '.'))
        {
            s2 += version2[j];
            j++;
        }

        if (!s1.empty())
        {
            num1 = stoi(s1);
        }

        if (!s2.empty())
        {
            num2 = stoi(s2);
        }

        if (num1 < num2)
        {
            return -1;
        }

        if (num1 > num2)
        {
            return 1;
        }
        ++i, ++j;
    }

    return 0;
}

// Zigzag Conversion
// O(N)
string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    string ans = "";
    int val = (numRows - 1) * 2;

    for (size_t row = 0; row < numRows; row++)
    {
        for (size_t i = row; i < s.length(); i += val)
        {
            ans += s[i];
            if ((row > 0) && (row < numRows - 1) && ((i + val - (2 * row)) < s.length()))
            {
                ans += s[i + val - (2 * row)];
            }
        }
    }

    return ans;
}

vector<string> prettyJSON(string s)
{
    vector<string> ans;
    string tab = "";
    bool characterFlag = 0;

    for (size_t i = 0; i < s.length(); i++)
    {
        if ((s[i] == '{') || (s[i] == '[') || (s[i] == ']') || (s[i] == '}'))
        {
            if (s[i] == '{' || s[i] == '[')
            {
                ans.push_back(tab + string(1, s[i]));
                tab += "\t";
            }
            else
            {
                string end = string(1, s[i]);
                if ((i + 1 < s.length()) && (s[i + 1] == ','))
                {
                    end += s[i + 1];
                    i++;
                }
                tab.pop_back();
                ans.push_back(tab + end);
            }
            continue;
        }
        string temp = "";

        while ((i < s.length()) && (s[i] != ',') && (s[i] != '{') && (s[i] != '[') && (s[i] != ']') && (s[i] != '}'))
        {
            temp += s[i++];
        }
        if (s[i] == ',')
        {
            temp += string(1, s[i]);
            i++;
        }
        --i;
        ans.push_back(tab + temp);
    }

    return ans;
}

int main()
{
    vector<string> strs = {"flower\n", "\tflow\n", "\t\tflight\n"};
    string s = "{A:\"B\",C:{D:\"E\",F:{G:\"H\",I:\"J\"}}}";

    for (auto &&i : prettyJSON(s))
    {
        cout << i << "\n";
    }

    // cout << reverseWords("lets go to 'new york'") << endl;
    // cout << myAtoi(" -9.87") << endl;
    // cout << longestCommonPrefix2(strs) << endl;
    // cout << longestPalindrome("CCC") << endl;
    return 0;
}