/*
Find the union and intersections of two arrays
Example: Arr 1: 1 3 1 4 7 9
         Arr 2: 2 1 4 6
            Union: 1 2 3 4 6 7 9
            Intersection: 1 4
Arrays maybe unsorted or in random format and in variable sizes also possible.  
*/
#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 3, 1, 4, 7, 9};
    int b[] = {2, 1, 4, 6};

    int n1 = 6, n2 = 4;

    int uni[20], inter[20];
    int u = 0, in = 0;

    // -------- UNION --------
    for (int i = 0; i < n1; i++)
    {
        bool found = false;
        for (int j = 0; j < u; j++)
        {
            if (uni[j] == a[i])
            {
                found = true;
                break;
            }
        }
        if (!found)
            uni[u++] = a[i];
    }

    for (int i = 0; i < n2; i++)
    {
        bool found = false;
        for (int j = 0; j < u; j++)
        {
            if (uni[j] == b[i])
            {
                found = true;
                break;
            }
        }
        if (!found)
            uni[u++] = b[i];
    }

    // -------- INTERSECTION --------
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j])
            {
                bool already = false;
                for (int k = 0; k < in; k++)
                {
                    if (inter[k] == a[i])
                    {
                        already = true;
                        break;
                    }
                }
                if (!already)
                    inter[in++] = a[i];
            }
        }
    }

    // Output
    cout << "Union: ";
    for (int i = 0; i < u; i++)
        cout << uni[i] << " ";

    cout << "\nIntersection: ";
    for (int i = 0; i < in; i++)
        cout << inter[i] << " ";

    return 0;
}
