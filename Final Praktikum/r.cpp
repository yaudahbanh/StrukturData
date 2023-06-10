#include <iostream>
#include <vector>
using namespace std;

string addLists(vector<int> &list1, vector<int> &list2)
{
    int carry = 0;
    int i = list1.size() - 1;
    int j = list2.size() - 1;
    string sum = "";

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int digit1 = (i >= 0) ? list1[i] : 0;
        int digit2 = (j >= 0) ? list2[j] : 0;
        int total = digit1 + digit2 + carry;
        int newDigit = total % 10;
        carry = total / 10;

        sum = to_string(newDigit) + sum;

        i--;
        j--;
    }

    return sum;
}

int main()
{
    int M, N;
    cin >> M >> N;

    vector<int> list1(M);
    vector<int> list2(N);

    for (int i = 0; i < M; i++)
    {
        cin >> list1[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> list2[i];
    }

    string result = addLists(list1, list2);
    cout << result << endl;

    return 0;
}
