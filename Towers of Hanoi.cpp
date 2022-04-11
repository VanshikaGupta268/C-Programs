#include <iostream>
using namespace std;
void tower (int n, char source, char temp, char destination);
int main()
{
    int num;
    char source='A',auxiliary='B',destination='C';
    cout<<"Enter the value of number of disks:";
    cin>>num;
    tower(num,source,auxiliary,destination);
    return 0;
}
void tower(int n, char source, char aux, char destination) {
if(n==1) 
{
cout<<"move disk 1 from "<<source<<" to "<<destination<<endl;
return;
}
//moving n-1 disks from A to B using C as auxiliary
tower(n-1, source, destination, aux);
cout<<"move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
//*moving n-1 disks from B to C using A as auxiliary
tower(n-1, aux, source, destination);
}
