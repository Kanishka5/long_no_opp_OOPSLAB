#include <bits/stdc++.h>

using namespace std;

void sum(string x, string y)
{
    int a = x.length();
    int b = y.length();
    int n = a > b ? a : b;
    int c = 0;
    string s;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int m = x[a - 1] - '0';
        int k = y[b - 1] - '0';
        //cout << m <<"\n";
        if (a > 0 && b > 0)
        {
            int t = m + k + c;
            int d = t % 10;
            v.push_back(d);
            c = t / 10;
        }
        else if (a < b)
        {
            int t = k + c;
            int d = t % 10;
            v.push_back(d);
            c = t / 10;
        }
        else if (b < a)
        {
            int t = m + c;
            int d = t % 10;
            v.push_back(d);
            c = t / 10;
        }
        a--;
        b--;
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
        s[i] = v[i];
    }
    cout << "\n";
}

void diff(string x, string y)
{
    int i;
    long long int a, b, c;
    int arr1[100] = {0}, arr2[100] = {0}, arr[1000] = {0}, carry = 0;
    long long int n1, n2;
    n1 = x.size();
    n2 = y.size();
    c = (n1 > n2) ? n1 : n2;
    for (i = 1; i <= x.size(); i++)
    {
        int m = x.size();
        a = (int)x[m - i] - 48;
        arr1[c - i + 1] = a;
    }
    for (i = 1; i <= y.size(); i++)
    {
        int m = y.size();
        b = (int)y[m - i] - 48;
        arr2[c - i + 1] = b;
    }
    if (n1 > n2)
    {
        for (i = c; i >= 0; i--)
        {
            if (arr1[i] < (arr2[i] + carry))
            {
                arr[i] = (10 + arr1[i] - arr2[i] - carry);
                carry = 1;
            }
            else
            {
                arr[i] = (arr1[i] - arr2[i] - carry);
                carry = 0;
            }
        }
    }
    else if (n1 < n2)
    {
        for (i = c; i >= 0; i--)
        {
            if (arr2[i] < (arr1[i] + carry))
            {
                arr[i] = (10 + arr2[i] - arr1[i] - carry);
                carry = 1;
            }
            else
            {
                arr[i] = (arr2[i] - arr1[i] - carry);
                carry = 0;
            }
        }
    }
    else if (n1 == n2 && arr1[0] <= arr2[0])
    {
        for (i = c; i >= 0; i--)
        {
            if (arr2[i] < (arr1[i] + carry))
            {
                arr[i] = (10 + arr2[i] - arr1[i] - carry);
                carry = 1;
            }
            else
            {
                arr[i] = (arr2[i] - arr1[i] - carry);
                carry = 0;
            }
        }
    }
    else if (n1 == n2 && arr1[0] > arr2[0])
    {
        for (i = c; i >= 0; i--)
        {
            if (arr1[i] < (arr2[i] + carry))
            {
                arr[i] = (10 + arr1[i] - arr2[i] - carry);
                carry = 1;
            }
            else
            {
                arr[i] = (arr1[i] - arr2[i] - carry);
                carry = 0;
            }
        }
    }
    int t = 0;
    for (i = 0; i <= c; i++)
    {
        if (arr[i] == 0)
        {
            t++;
        }
        else
        {
            break;
        }
    }
    for (i = t; i <= c; i++)
    {
        cout << arr[i];
    }
    cout << "\n";
}

void multiply(string x, string y)
{
    int arr1[1000] = {0}, arr2[1000] = {0}, arr[2050] = {0};
    int n1, n2, i, c, j;
    n1 = x.size();
    n2 = y.size();
    c = (n1 > n2) ? n1 : n2;
    for (i = 0; i < n1; i++)
    {
        arr1[2 * c - i - 1] = (int)x[n1 - i - 1] - 48;
    }
    for (j = 0; j < n2; j++)
    {
        arr2[2 * c - j - 1] = (int)y[n2 - j - 1] - 48;
    }
    int carry = 0;
    for (i = 0; i < n2; i++)
    {
        carry = 0;
        for (j = 0; j <= n1; j++)
        {
            int a = arr[2 * c - i - j - 1];
            arr[2 * c - i - j - 1] = (carry + arr[2 * c - i - j - 1] + arr1[2 * c - j - 1] * arr2[2 * c - i - 1]) % 10;
            carry = (carry + a + arr1[2 * c - j - 1] * arr2[2 * c - i - 1]) / 10;
        }
    }
    int t = 0;
    for (i = 0; i, 2 * c; i++)
    {
        if (arr[i] == 0)
        {
            t++;
        }
        else
        {
            break;
        }
    }
    for (i = t; i < 2 * c; i++)
    {
        cout << arr[i];
    }
    cout << "\n";
}

int div(string x, string y)
{
    long long int n1, n2, i, j, c, d = 0, r = 0, s = 0, t = 0, p = 0, a;
    n1 = x.size();
    n2 = y.size();
    c = (n1 > n2) ? n1 : n2;
    long long int arr1[1000] = {0}, arr2[1000] = {0}, arr[1000] = {0};
    if (n1 < n2)
    {
        cout << "0";
        return 0;
    }
    else if (n1 == n2)
    {
        for (i = 0; i < n1; i++)
        {
            d = d * 10 + (int)x[i] - 48;
        }
        for (i = 0; i < n2; i++)
        {
            t = t * 10 + (int)y[i] - 48;
        }
        t = d / t;
        cout << t;
        return 0;
    }
    else
    {
        for (i = 0; i < n1; i++)
        {
            arr1[i] = (int)x[i] - 48;
        }
        for (i = 0; i < n2; i++)
        {
            d = d * 10 + (int)y[i] - 48;
        }
    }
    for (i = 0; i < c; i++)
    {
        for (j = t; j < (r + t); j++)
        {
            if (j == c - 1)
            {
                i = c;
            }
            else
            {
                s = s * 10 + (int)x[j] - 48;
            }
        }
        if (d <= s)
        {
            a = s / d;
            arr[p++] = a;
            s = s - a * d;
            t = t + r;
        }
        else
        {
            s = s * 10 + (int)x[t + r] - 48;
            a = s / d;
            arr[p++] = a;
            s = s - a * d;
            t++;
        }
    }
    t = 0;
    for (i = 0; i < p; i++)
    {
        if (arr[i] == 0)
        {
            t++;
        }
    }
    for (i = t; i < p; i++)
    {
        cout << arr[i];
    }
    cout << "\n";
}

int main()
{
    string x, y, z;
    cout << "Enter 2 numbers";
    cin >> x >> y;
    cout << "SUM: \t";
    sum(x, y);
    cout << "DIFFERENCE: \t";
    diff(x, y);
    cout << "MULTIPLY: \t";
    multiply(x, y);
    cout << "DIVISION: \t";
    div(x, y);
    return 0;
}
