#include<iostream>
#include<conio.h>

using namespace std;

class Array{
private:
    int *A;
    int size;
    int length;
    void Swap(int *a, int *b){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
public:
    Array(){
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz, int ln){
        size = sz;
        length = ln;
        A = new int[size];
    }

    ~Array(){
        delete []A;
    }

    void Start(int index, int x);
    void Display();
    bool Add(int x);
    bool Insert(int index, int x);
    int Delete(int index);
    int Linear(int x);
    int Linear_T(int x);
    int Linear_MTF(int x);
    int Binary_L(int x);
    int Get(int index);
    bool Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    double Average();
};

void Array::Start(int index, int x){
    A[index] = x;
}

void Array::Display(){
    for(int i=0; i<length; i++){
        cout << i <<". " << A[i] << endl;
    }
}

bool Array::Add(int x){
    if(length<size){
        A[length] = x;
        length++;
        return 1;
    }
    return 0;
}

bool Array::Insert(int index, int x){
    
    if(index >= 0 && index <= length){
        for(int i = length; i>index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
        return 1;
    }
    else
        return 0;
}

int Array::Delete(int  index){
    int x = 0;
    if(index >= 0 && index <= length){
        x = A[index];
        for(int i = index; i<length-1; i++){
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return -1;
}

int Array::Linear(int x){
    for(int i=0; i<length; i++){
        if(A[i] == x)
            return i;
    }
    return -1;
}

int Array::Linear_T(int x){
    for(int i=0; i<length; i++){
        if(A[0] == x){
            return i;
        }else if(A[i] == x){
            Swap(&A[i], &A[i-1]);
            return --i;
        }
    }
    return -1;
}

int Array::Linear_MTF(int x){
    for(int i=0; i<length; i++){
        if(A[i] == x){
            Swap(&A[i], &A[0]);
            return 0;
        }
    }
    return -1;
}

int Array::Binary_L(int x){
    int l=0, h=length;
    int mid;
    while(l<=h){
        mid = (l+h)/2;
        if(A[mid] == x)
            return mid;
        else if(A[mid] > x)
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int Array::Get(int index){
    if(index>=0 && index<length)
        return A[index];
    return -1;
}

bool Array::Set(int index, int x){
    if(index>=0 && index<length){
        A[index] = x;
        return 1;
    }
    return 0;
}

int Array::Max(){
    int max = A[0];
    for(int i=1; i<length; i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

int Array::Min(){
    int min = A[0];
    for(int i=1; i<length; i++){
        if(A[i] < min)
            min = A[i];
    }
    return min;
}

int Array::Sum(){
    int sum = 0;
    for(int i=0; i<length; i++){
        sum += A[i];
    }
    return sum;
}

double Array::Average(){
    double sum = 0;
    for(int i=0; i<length; i++){
        sum += A[i];
    }
    return sum/length;
}
int main(){
    system ("CLS");

    int sz, ln, i, indx, x, ch=1;

    cout<<"What is the size of an Array:\t";
    cin>>sz;
    cout<<"How many elements you want to enter:\t";
    cin>>ln;

    Array arr(sz, ln);

    cout<<"\nStart Entering Elemets:"<<endl;
    for(i=0;i<ln;i++){
        cin>>x;
        arr.Start(i,x);
    }

    do{
        system ("CLS");
        cout<<"*****MAIN MENU*****"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"1. Display"<<endl;
        cout<<"2. Add"<<endl;
        cout<<"3. Insert"<<endl;
        cout<<"4. Delete"<<endl;
        cout<<"5. Search >>"<<endl;
        cout<<"6. Get"<<endl;
        cout<<"7. Set"<<endl;
        cout<<"8. Max"<<endl;
        cout<<"9. Min"<<endl;
        cout<<"10. Sum"<<endl;
        cout<<"11. Average"<<endl;
        cout<<"\nEnter your choice:\t";
        cin>>ch;
    
        switch(ch){
            case 1: system ("CLS");
                    cout<<"*****Displaying*****"<<endl;
                    arr.Display();

                    cout<<"\nPress any key to continue."<<endl;
                    getch();
                    break;
                    
            case 2: system ("CLS");
                    cout<<"Enter an element:\t";
                    cin>>x;
                
                    if(arr.Add(x))
                        cout<<"*****Element Added successfully*****"<<endl;
                    else
                        cout<<"Something went wrong!!"<<endl;
                    
                    cout<<"\nPress any key to continue."<<endl;
                    getch();
                    break;


            case 3: system ("CLS");
                    cout<<"At which index you want to insert:\t";
                    cin>>indx;
                    cout<<"Enter an Element:\t";
                    cin>>x;
                    if(arr.Insert(indx, x))
                        cout<<"*****Element Inserted successfully*****"<<endl;
                    else
                        cout<<"Length is over than size of an array!!"<<endl;

                    cout<<"\nPress any key to continue."<<endl;
                    getch();
                    break;
            
            case 4: system ("CLS");
                    cout<<"At which index you want to delete element:\t";
                    cin>>indx;

                    x = arr.Delete(indx);
                    
                    if(x>=0)
                        cout<<"*****Element Deleted successfully*****"<<endl;
                    else
                        cout<<"*****INVALID INDEX*****"<<endl;
                        
                    cout<<"\nPress any key to continue."<<endl;
                    getch();
                    break;
                    
            case 5: do{
                        system ("CLS");
                        cout<<"*****SEARCH ALGORITHMS*****"<<endl;
                        cout<<"1. Display"<<endl;
                        cout<<"2. Linear Search"<<endl;
                        cout<<"3. Linear Search (TRANSPOSITION)"<<endl;
                        cout<<"4. Linear Search (MOVE TO FRONT)"<<endl;
                        cout<<"5. Binary Search (LOOP)"<<endl;
                        cout<<"9. BACK"<<endl;
                        cout<<"\nEnter your choice:\t";
                        cin>>ch;
                        switch(ch){
                            case 1: system ("CLS");
                                    cout<<"*****Displaying*****"<<endl;
                                    arr.Display();

                                    cout<<"\nPress any key to continue."<<endl;
                                    getch();
                                    break;

                            case 2: system ("CLS");
                                    cout<<"Enter an Element:\t";
                                    cin>>x;
                                    indx = arr.Linear(x);
                                    if(indx>=0)
                                        cout<<"Element found at index: "<< indx << endl;
                                    else
                                        cout<<"Element Not Found!!"<<endl;

                                    cout<<"\nPress any key to continue."<<endl;
                                    getch();
                                    break;
                            
                            case 3: system ("CLS");
                                    cout<<"Enter an Element:\t";
                                    cin>>x;
                                    indx = arr.Linear_T(x);
                                    if(indx>=0)
                                        cout<<"Element found at index: "<< indx << endl;
                                    else
                                        cout<<"Element Not Found!!"<<endl;

                                    cout<<"\nPress any key to continue."<<endl;
                                    getch();
                                    break;
                            
                            case 4: system ("CLS");
                                    cout<<"Enter an Element:\t";
                                    cin>>x;
                                    indx = arr.Linear_MTF(x);
                                    if(indx>=0)
                                        cout<<"Element found at index: "<< indx << endl;
                                    else
                                        cout<<"Element Not Found!!"<<endl;

                                    cout<<"\nPress any key to continue."<<endl;
                                    getch();
                                    break;
                            
                            case 5: system ("CLS");
                                    cout<<"Enter an Element:\t";
                                    cin>>x;
                                    indx = arr.Binary_L(x);
                                    if(indx>=0)
                                        cout<<"Element found at index: "<< indx << endl;
                                    else
                                        cout<<"Element Not Found!!"<<endl;

                                    cout<<"\nPress any key to continue."<<endl;
                                    getch();
                                    break;
                        }
                    }while(ch!=9);
                    break;
            
            case 6: system ("CLS");
                    cout<<"Enter a Index:\t";
                    cin>>indx;
                    x = arr.Get(indx);
                    if(x>=0)
                        cout<<"Element found at index "<< indx <<" is:\t"<< x << endl;
                    else
                        cout<<"Invalid Index!!"<<endl;

                    cout<<"\nPress any key to continue."<<endl;
                    getch();
                    break;
            
            case 7: system ("CLS");
                    cout<<"At which index you want to insert:\t";
                    cin>>indx;
                    cout<<"Enter an Element:\t";
                    cin>>x;
                    if(arr.Set(indx, x))
                        cout<<"*****Element Set successfully*****"<<endl;
                    else
                        cout<<"Invalid Index!!"<<endl;

                    cout<<"\nPress any key to continue."<<endl;
                    getch();
                    break;

            case 8: system ("CLS");
                    x = arr.Max();
                    cout<<"Maximum Element of an array is: "<< x <<endl;

                    cout<<"\nPress any key to continue."<<endl;
                    getch();
                    break;
            
            case 9: system ("CLS");
                    x = arr.Min();
                    cout<<"Minimum Element of an array is: "<< x <<endl;

                    cout<<"\nPress any key to continue."<<endl;
                    getch();
                    break;

            case 10: system ("CLS");
                    x = arr.Sum();
                    cout<<"Sum of all Elements of an array is: "<< x <<endl;

                    cout<<"\nPress any key to continue."<<endl;
                    getch();
                    break;
            
            case 11: system ("CLS");
                    // x = arr.Average();
                    cout<<"Average of all Elements of an array is: "<< arr.Average() <<endl;

                    cout<<"\nPress any key to continue."<<endl;
                    getch();
                    break;
        }
    }while(ch!=0);
    return 0;    
}