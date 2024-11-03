#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */
 
struct Heap
{
    int arr[1000000];
    int sz = 0;

    void insert(int val)
    {
        arr[sz++] = val;
    }

    void heapify(int n, int indx)
    {
        int left_indx = indx * 2 + 1;
        int right_indx = indx * 2 + 2;

        int max_indx = indx;
        if (left_indx < n && arr[left_indx] > arr[max_indx])
        {
            max_indx = left_indx;
        }
        if (right_indx < n && arr[right_indx] > arr[max_indx])
        {
            max_indx = right_indx;
        }

        if (indx != max_indx)
        {
            int temp = arr[indx];
            arr[indx] = arr[max_indx];
            arr[max_indx] = temp;

            heapify(n, max_indx);
        }
    }

    void max_heap()
    {
        for (int i = sz / 2 - 1; i >= 0; i--)
        {
            heapify(sz, i);
        }
    }

    void heap_sort()
    {
        max_heap();

        for (int i = sz - 1; i >= 0; i--)
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(i, 0);
        }
    }

    void deleteNode(int num)
    {
        int pos = 0;
        for (int i = 0; i < sz; i++)
        {
            if (num == arr[i])
            {
                pos = i;
                break;
            }
        }

        int temp = arr[pos];
        arr[pos] = arr[sz - 1];
        arr[sz - 1] = temp;

        sz--;

        for (int i = sz / 2 - 1; i >= 0; i--)
        {
            heapify(sz, i);
        }
    }

    int top()
    {
        return arr[sz-1];
    }

    int size()
    {
        return sz;
    }

    void make_neg()
    {
        for(int i=0; i<sz; i++)
        {
            arr[i] = -arr[i];
        }
    }

    void print_array()
    {
        for (int i = 0; i < sz; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};


int cookies(int k, vector<int> A)
{
    // Heap* heap = new Heap();

    int n = A.size();
    priority_queue<int> mst;

    for (int i = 0; i < n; i++)
    {
        // heap->insert(A[i]);
        mst.push(-A[i]);
    }

    int cnt = 0;
    // while (heap->top() < k && heap->size() > 1)
    while (-mst.top() < k && mst.size() > 1)
    {
        // int x = heap->top();
        // heap->deleteNode(x);
        // int y = heap->top();
        // heap->deleteNode(y);


        int x = -mst.top();
        mst.pop();
        int y = -mst.top();
        mst.pop();
        
        // heap->insert((y * 2 + x));
        mst.push(-(y * 2 + x));
        cnt++;
    }

    // return (heap->top() < k ? -1 : cnt);
    return (-mst.top() < k ? -1 : cnt);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
