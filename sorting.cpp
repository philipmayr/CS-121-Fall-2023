#include "random.h"
#include <ctype.h>
#include <iostream>
#include <limits>
#include <vector>
#include <ctime>

using namespace std;

typedef vector<long>::size_type vec_lng_sz;

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

template <typename Base_Type> 
typename vector<Base_Type>::size_type 
find_smallest(vector<Base_Type> list, 
              typename vector<Base_Type>::size_type start_position = 0);

template <typename Base_Type> 
void selection_sort(vector<Base_Type> &list);

template <typename Base_Type> 
void selection_sort(vector<Base_Type> &list, 
                    typename vector<Base_Type>::size_type start, 
                    typename vector<Base_Type>::size_type end);

template <typename Base_Type> 
void insertion_sort(vector<Base_Type> &list);

template <typename Base_Type> 
void insertion_sort(vector<Base_Type> &list, 
                    typename vector<Base_Type>::size_type start, 
                    typename vector<Base_Type>::size_type end);

template <typename Base_Type> 
void bubble_sort(vector<Base_Type> &list);

template <typename Base_Type> 
void bubble_sort(vector<Base_Type> &list, 
                 typename vector<Base_Type>::size_type start, 
                 typename vector<Base_Type>::size_type end);

template <typename Base_Type> 
bool is_sorted(vector<Base_Type> &list, 
               typename vector<Base_Type>::size_type start, 
               typename vector<Base_Type>::size_type end);

template <typename Base_Type> 
void compare_sorts(vector<Base_Type> list, long runs);

void report_times(time_t start, time_t end, long runs, string label);

int main()
{
    string welcome = "Welcome to the Sorting Algorithm Comparison Program.";
    cout << "\n" 
         << string((80 - welcome.length()) / 2, ' ') << welcome 
         << "\n";

    vec_lng_sz len;
    vector<long> list;
    long lower_bound, upper_bound;

    char y_n;

    cout << "\nNew vector to be initialized with random values. \n"
            "Would you rather fill in vector values by hand?\n"
            "Enter y/n: ";
    
    cin >> y_n;
    cin.ignore(INF_FLAG, '\n');

    srand(static_cast<unsigned>(time(nullptr)));

    if (tolower(y_n) != 'n')
    {
        cout << "\nEnter vector values below -one per line- "
             << "and enter 'done' to stop:\n";
        long value = 0;
        for (;;) 
        {
            cin >> value;
            cin.ignore(INF_FLAG, '\n'); 
            if (!cin.fail())
            {
                list.push_back(value);
            }
            else
            {
                cin.clear();
                cin.ignore(INF_FLAG, '\n'); 
                break;
            }
        }
        cout << "\nVector of size " << list.size() 
             << " initialized and filled in:\n";
    }
    else
    {
        cout << "\nEnter number of elements to initialize vector with:\n";
        cin >> len;
        cin.ignore(INF_FLAG, '\n'); 
        cout << "\nEnter lower and upper bounds (both inclusive) "
                "for range of random value generator.\n"
             << "lower bound: ";
        cin >> lower_bound;
        cin.ignore(INF_FLAG, '\n'); 
        cout << "upper bound: ";
        cin >> upper_bound;
        cin.ignore(INF_FLAG, '\n'); 

        for (vec_lng_sz i = 0; i < len; i++)
        {
            // rand min and max both inclusive
            list.push_back(get_random_num(lower_bound, upper_bound));
        }

        cout << "\nVector of size " << len 
             << " initialized and filled in with random values:\n";
    }

    vector<long> og_list = list;

    cout << "\n";

    for (vec_lng_sz i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }

    cout << "\n\nChoose sorting algorithm: \n\n"
            "Enter:\n's' for selection sort, "
            "\n'i' for insertion sort, "
            "\n'b' for bubble sort:\n ";

    char sort_choice;
    cin >> sort_choice;
    cin.ignore(INF_FLAG, '\n');

    for (;;)
    {
        if (!(tolower(sort_choice) == 's' || 
              tolower(sort_choice) == 'i' ||
              tolower(sort_choice) == 'b'))
        {
            cout << "\nInvalid choice.";

            cout << "\n\nChoose sorting algorithm: \n\n"
            "Enter:\n's' for selection sort, "
            "\n'i' for insertion sort, "
            "\n'b' for bubble sort:\n ";

            cin >> sort_choice;
            cin.ignore(INF_FLAG, '\n');
            sort_choice = char(tolower(sort_choice));
        }
        else
        {
            break;
        }
    }

    vec_lng_sz start, end;

    cout << "\nAll values will be sorted by default. \n"
         << "Would you rather sort only those values within a subrange?\n"
         << "Enter y/n: ";
    cin >> y_n;
    cin.ignore(INF_FLAG, '\n');    

    if (tolower(y_n) != 'n')
    {
        cout << "\nEnter vector subrange start index: ";
        cin >> start;
        cin.ignore(INF_FLAG, '\n'); 
        cout << "Enter vector subrange end index: ";
        cin >> end;
        cin.ignore(INF_FLAG, '\n'); 
    }
    else
    {
        start = 0;
        end = list.size() - 1;
    }

    switch(sort_choice) 
    {
        case 's':
            selection_sort(list, start, end);
            if (is_sorted(list, start, end))
            {
                cout << "\nVector sorted using selection sort.\n";
            }
        break; 
        case 'i':
            insertion_sort(list, start, end);
            if (is_sorted(list, start, end))
            {
                cout << "\nVector sorted using insertion sort.\n";
            }
        break;
        case 'b':
            bubble_sort(list, start, end);
            if (is_sorted(list, start, end))
            {
                cout << "\nVector sorted using bubble sort.\n";
            }
        break;
        default:
            cout << "\n\nInvalid choice.\n";
            return 0;
    }

    cout << "\nWould you like to print the sorted vector?\n"
            "Enter y/n: ";
    cin >> y_n;
    cin.ignore(INF_FLAG, '\n');

    if (tolower(y_n) != 'n')
    {
        for (vec_lng_sz i = 0; i < list.size(); i++)
        {
            cout << list[i] << " ";
        }
    }

    long runs;
    cout << "\n\nEnter number of times to run all three sorting algorithms"
         << " on original vector:\n";
    cin >> runs;
    compare_sorts(og_list, runs);
    
    cout << "\n";

	return 0;
}

template <typename Base_Type> 
void compare_sorts(vector<Base_Type> list, long runs)
{
    time_t start, end;

    start = time(nullptr);
    vector<Base_Type> unsorted_list = list;
    for (long i = 0; i < runs; i++)
    {
        list = unsorted_list;
        selection_sort(list);
    }
    end = time(nullptr);
    report_times(start, end, runs, "Selection");

    start = time(nullptr);
    for (long i = 0; i < runs; i++)
    {
        list = unsorted_list;
        insertion_sort(list);
    }
    end = time(nullptr);
    report_times(start, end, runs, "Insertion");

    start = time(nullptr);
    for (long i = 0; i < runs; i++)
    {
        list = unsorted_list;
        bubble_sort(list);
    }
    end = time(nullptr);
    report_times(start, end, runs, "Bubble");
}

void report_times(time_t start, time_t end, long runs, string label)
{
    double ms = static_cast<double>((end-start) * 1000);
    cout << "\n" << label << " sort took " 
         << (ms/static_cast<double>(runs)) 
         << " ms on average." << endl;
    cout << "Total time (" << runs << " runs): " 
         << ms << " ms." << endl;
}

template <typename Base_Type> 
typename vector<Base_Type>::size_type 
find_smallest(vector<Base_Type> list, 
              typename vector<Base_Type>::size_type start_position)
{
    typename vector<Base_Type>::size_type min = start_position;
    for (vec_lng_sz position = start_position + 1; 
         position < list.size(); position++)
    {
        if (list[position] < list[min])
        {
            min = position;
        }
    }
    return min;
}

template <typename Base_Type>
void selection_sort(vector<Base_Type> &list)
{
    selection_sort(list, 0, list.size());
}

template <typename Base_Type> 
void selection_sort(vector<Base_Type> &list, 
                    typename vector<Base_Type>::size_type start, 
                    typename vector<Base_Type>::size_type end)
{
    typename vector<Base_Type>::size_type min = find_smallest(list, start);

    for(typename vector<Base_Type>::size_type position = start; 
        position < end; position++)
    {
        if (min != position)
        {
            swap(list[position], list[min]);
        }
        min = find_smallest(list, position + 1);
    }
}

template <typename Base_Type> 
void insertion_sort(vector<Base_Type> &list)
{
   insertion_sort(list, 0, list.size());
}

template <typename Base_Type> 
void insertion_sort(vector<Base_Type> &list, 
                    typename vector<Base_Type>::size_type start, 
                    typename vector<Base_Type>::size_type end)
{
    typename vector<Base_Type>::size_type j;
    long key;
    for (typename vector<Base_Type>::size_type i = start + 1;
         i < end + 1; i++)
    {
        key = list[i];
        j = i;
        while (j > start && list[j - 1] > key)
        {
            list[j] = list[j - 1];
            j--;
        }
        list[j] = key;
    }
}

template <typename Base_Type> 
void bubble_sort(vector<Base_Type> &list)
{
    bubble_sort(list, 0, list.size());
}

template <typename Base_Type> 
void bubble_sort(vector<Base_Type> &list, 
                 typename vector<Base_Type>::size_type start, 
                 typename vector<Base_Type>::size_type end)
{
    for (typename vector<Base_Type>::size_type i = start; i < end; i++)
    {   
        bool swap_flag = false;
        for (typename vector<Base_Type>::size_type j = start; j < end; j++)
        {
            if (list[j] > list[j + 1])
            {
                swap(list[j], list[j + 1]);
                swap_flag = true;
            }
        }
        if (!swap_flag)
        {
            break;
        }
    }
}

template <typename Base_Type> 
bool is_sorted(vector<Base_Type> &list, 
               typename vector<Base_Type>::size_type start, 
               typename vector<Base_Type>::size_type end)
{
    bool flag = false;
    for (typename vector<Base_Type>::size_type j = start; j < end; j++)
    {
        if (list[j] > list[j + 1])
        {
            flag = true;
        }
    }
    return flag;
}

