#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Vector2D;
class Vector3D;

class Vector
{
protected:
    static string type;
public:
    virtual string getType()=0;
    virtual double dot(Vector&)=0;
    virtual double dot(Vector2D&)=0;
    virtual double dot(Vector3D&)=0;
    virtual double mod()=0;
    virtual Vector* unit()=0;
    virtual void print()=0;

    virtual Vector* operator + (Vector&) =0;
    virtual Vector* operator + (Vector2D&) =0;
    virtual Vector* operator + (Vector3D&) =0;
    virtual Vector* operator - (Vector&) =0;
    virtual Vector* operator - (Vector2D&) =0;
    virtual Vector* operator - (Vector3D&) =0;
    virtual Vector* operator * (Vector&)=0;
    virtual Vector* operator * (Vector2D&) =0;
    virtual Vector* operator * (Vector3D&) =0;
    virtual Vector* operator ++() =0;
    virtual Vector* operator ++(int) =0;
    virtual bool operator == (Vector&) =0;
    virtual bool operator == (Vector2D&) =0;
    virtual bool operator == (Vector3D&) =0;
};
class Vector2D : public Vector
{
protected:
    double i;
    double j;
public:
    Vector2D(double i, double j) : i(i),j(j){}

    string getType();
    double dot(Vector& v);
    double dot(Vector2D& v);
    double dot(Vector3D& v);
    double mod();
    Vector* unit();
    void print();

    Vector* operator + (Vector& v);
    Vector* operator + (Vector2D& v);
    Vector* operator + (Vector3D& v);
    Vector* operator - (Vector& v);
    Vector* operator - (Vector2D& v);
    Vector* operator - (Vector3D& v);
    Vector* operator * (Vector& v);
    Vector* operator * (Vector2D& v);
    Vector* operator * (Vector3D& v);
    Vector* operator ++();
    Vector* operator ++(int);
    bool operator == (Vector& v);
    bool operator == (Vector2D& v);
    bool operator == (Vector3D& v);

    double get_i()
    {
        return i;
    }
    double get_j()
    {
        return j;
    }
};
class Vector3D : public Vector2D
{
protected:
    double k;
public:
    Vector3D(double i, double j, double k) : Vector2D(i,j),k(k) {}

    string getType();
    double dot(Vector& v);
    double dot(Vector2D& v);
    double dot(Vector3D& v);
    double mod();
    Vector* unit();
    void print();

    Vector* operator + (Vector& v);
    Vector* operator + (Vector2D& v);
    Vector* operator + (Vector3D& v);
    Vector* operator - (Vector& v);
    Vector* operator - (Vector2D& v);
    Vector* operator - (Vector3D& v);
    Vector* operator * (Vector& v);
    Vector* operator * (Vector2D& v);
    Vector* operator * (Vector3D& v);
    Vector* operator ++();
    Vector* operator ++(int);
    bool operator == (Vector& v);
    bool operator == (Vector2D& v);
    bool operator == (Vector3D& v);

    double get_k()
    {
        return k;
    }
    void set_k(double k)
    {
        this->k=k;
    }
};
///cross product
Vector* Vector2D :: operator * (Vector& v)
{
    return v*(*this);
}
Vector* Vector3D :: operator * (Vector& v)
{
    return v*(*this);
}
Vector* Vector2D :: operator * (Vector2D& v)
{
    Vector3D *v1 = new Vector3D(0,0,0);
    v1->i=0;
    v1->j=0;
    double h= v.get_i()*(this->j) - v.get_j()*(this->i);
    v1->set_k(h);
    return v1;
}
Vector* Vector3D :: operator * (Vector3D& v)
{
    Vector3D *v1 = new Vector3D(0,0,0);
    v1->i=v.get_j()*(this->k) - v.get_k()*(this->j);
    v1->j=v.get_k()*(this->i) - v.get_i()*(this->k);
    v1->k= v.get_i()*(this->j) - v.get_j()*(this->i);

    return v1;
}
Vector* Vector3D :: operator * (Vector2D& v)
{
    Vector3D *v1 = new Vector3D(0,0,0);
    v1->i=v.get_j() * (this->k);
    v1->j=0 - v.get_i() * (this->k);
    v1->k= v.get_i()*(this->j) - v.get_j()*(this->i);

    return v1;
}
Vector* Vector2D :: operator * (Vector3D& v)
{
    Vector3D *v1 = new Vector3D(0,0,0);
    v1->i=0 - v.get_k()*(this->j);
    v1->j=v.get_k()*(this->i);
    double h= v.get_i()*(this->j) - v.j*(this->i);
    v1->set_k(h);

    return v1;
}
///Subtraction
Vector* Vector2D :: operator - (Vector& v)
{
    return v - (*this);
}
Vector* Vector3D :: operator - (Vector& v)
{
    return v - (*this);
}
Vector* Vector2D :: operator - (Vector2D& v)
{
    Vector2D *v1=new Vector2D(i,j);
    v1->i= v.i - this->i;
    v1->j=v.j - this->j;
    return v1;
}
Vector* Vector3D :: operator - (Vector3D& v)
{
    Vector3D *v1=new Vector3D(i,j,k);
    v1->i= v.i - this->i;
    v1->j=v.j - this->j;
    v1->k=v.k - this->k;
    return v1;
}
Vector* Vector2D :: operator - (Vector3D& v)
{
    Vector3D *v1=new Vector3D(i,j,0);
    v1->i= v.get_i() - this->i;
    v1->j=v.get_j() - this->j;
    v1->set_k(v.get_k());
    return v1;
}
Vector* Vector3D :: operator - (Vector2D& v)
{
    Vector3D *v1=new Vector3D(i,j,k);
    v1->i= v.get_i() - this->i;
    v1->j=v.get_j() - this->j;
    v1->k=0-this->k;
    return v1;
}
///dot product
double Vector2D :: dot(Vector& v)
{
    return v.dot(*this);
}
double Vector3D :: dot(Vector& v)
{
    return v.dot(*this);
}
double Vector2D :: dot(Vector2D& v)
{

    double d1= (v.get_i() )* i;
    double d2=(v.get_j()) * j;
    return d1+d2;
}
double Vector3D :: dot(Vector3D& v)
{

    double d1= (v.get_i()) * i;
    double d2=(v.get_j()) * j;
    double d3=(v.get_k()) * k;
    return d1+d2+d3;
}
double Vector3D :: dot(Vector2D& v)
{
   ;
    double d1=(v.get_i())*i;
    double d2=(v.get_j())*j;
    return d1+d2;
}
double Vector2D :: dot(Vector3D& v)
{
    return v.dot(*this);
}
/// addition
Vector* Vector2D :: operator + (Vector &v)
{
    return v + (*this);
}
Vector* Vector3D :: operator + (Vector &v)
{
    return v + (*this);
}
Vector* Vector2D :: operator + (Vector2D &v)
{
    Vector2D *v1=new Vector2D(i,j);
    v1->i= v.i + this->i;
    v1->j=v.j + this->j;
    return v1;
}
Vector* Vector3D :: operator + (Vector3D &v)
{
    Vector3D *v1=new Vector3D(i,j,k);
    v1->i= v.i + this->i;
    v1->j=v.j + this->j;
    v1->k=v.k + this->k;
    return v1;
}
Vector* Vector3D :: operator + (Vector2D &v)
{
    Vector3D *v1=new Vector3D(i,j,k);
    v1->i= v.get_i() + this->i;
    v1->j=v.get_j() + this->j;
    v1->k=this->k;
    return v1;
}
Vector* Vector2D :: operator + (Vector3D &v)
{
    return v + (*this);
}
/// testing equity
bool Vector2D :: operator == (Vector &v)
{
    return v ==(*this);
}
bool Vector3D :: operator == (Vector &v)
{
    return v==(*this);
}
bool Vector2D :: operator == (Vector2D &v)
{
    if(v.i==this->i && v.j==this->j)
        return true;
    else
        return false;
}
bool Vector3D :: operator == (Vector3D &v)
{
    if(v.i==this->i && v.j==this->j && v.k==this->k)
        return true;
    else
        return false;
}
bool Vector2D :: operator == (Vector3D &v)
{
    if(v.get_i()==this->i && v.get_j()==this->j && v.get_k()==0 )
        return true;
    else
        return false;
}
bool Vector3D :: operator == (Vector2D &v)
{
    return v==(*this);
}
/// postfix
Vector* Vector3D :: operator ++(int)
{
    Vector3D *v=new Vector3D(i,j,k);
    v->i=this->i;
    v->j=this->j;
    v->k=this->k;
    this->i=this->i+1;
    this->j=this->j+1;
    this->k=this->k+1;
    return v;
}
Vector* Vector2D :: operator ++(int)
{
    Vector2D *v=new Vector2D(i,j);
    v->i=this->i;
    v->j=this->j;
    this->i=this->i+1;
    this->j=this->j+1;
    return v;
}
/// prefix
Vector* Vector3D :: operator ++()
{
    this->i=this->i+1;
    this->j=this->j+1;
    this->k=this->k+1;
    return this;
}
Vector* Vector2D :: operator ++()
{
    this->i=this->i+1;
    this->j=this->j+1;
    return this;
}
///finding modulus
double Vector2D :: mod()
{
    return sqrt(i*i+j*j);
}
double Vector3D :: mod()
{
    return sqrt(i*i+j*j+k*k);
}
///finding unit vector
Vector* Vector2D :: unit()
{
   Vector2D *v=new Vector2D(i,j);
   double mod= this->mod();
   v->i=(this->i)/mod;
   v->j=(this->j)/mod;

   return v;
}
Vector* Vector3D :: unit()
{
   Vector3D *v=new Vector3D(i,j,k);
   double mod= this->mod();
   v->i=(this->i)/mod;
   v->j=(this->j)/mod;
   v->k=(this->k)/mod;
   return v;
}
///getting type
string Vector :: type;
string Vector2D ::getType()
{
    type="Vector2D";
    return type;
}
string Vector3D ::getType()
{
    type="Vector3D";
    return type;
}
///printing vector
void Vector2D :: print()
{
    if(j<0)
        cout<<i<<"i"<<j<<"j";
    else
        cout<<i<<"i+"<<j<<"j";
}
void Vector3D :: print()
{
    if(j<0 && k<0)
        cout<<i<<"i"<<j<<"j"<<k<<"k";

    else if (j<0)
        cout<<i<<"i"<<j<<"j+"<<k<<"k";

    else if(k<0)
        cout<<i<<"i+"<<j<<"j"<<k<<"k";

    else
        cout<<i<<"i+"<<j<<"j+"<<k<<"k";
}


int main()
{
    int n,m,choice,index1,index2;
    double i,j,k;

    cout<<"Enter how many vectors you want to enter"<<endl<<"->";
    cin>>n;

     Vector *vect[n];

    for(m=0; m<n; m++) /// taking input
    {
        if((m+1)%10==1)
            cout<<"Enter Your Choice for "<<(m+1)<<"st Vector:"<<endl;
        else if((m+1)%10==2)
            cout<<"Enter Your Choice for "<<(m+1)<<"nd Vector:"<<endl;
        else if((m+1)%10==3)
            cout<<"Enter Your Choice for "<<(m+1)<<"rd Vector:"<<endl;
        else
            cout<<"Enter Your Choice for "<<(m+1)<<"th Vector:"<<endl;

        cout<<"  1)2D Vector"<<endl<<"  2)3D Vector"<<endl<<"->";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter i and j Component:"<<endl;
            cin>>i>>j;

            vect[m]=new Vector2D(i,j);
        }
        else if(choice==2)
        {
            cout<<"Enter i, j and k Component:"<<endl;
            cin>>i>>j>>k;

            vect[m]=new Vector3D(i,j,k);
        }
    }
    while(1) ///Menu driven part
    {
        cout<<"Enter Your Choice:"<<endl;
        cout<<"  1)Print"<<endl<<"  2)Get Type"<<endl<<"  3)Unit Vector"<<endl<<"  4)Modulus Value"<<endl<<"  5)Dot Product"<<endl;
        cout<<"  6)Cross Product"<<endl<<"  7)Addition"<<endl<<"  8)Subtraction"<<endl<<"  9)Postfix"<<endl<<"  10)Prefix"<<endl;
        cout<<"  11)Is Equal"<<endl<<"  0)Exit"<<endl<<"->";
        cin>>choice;

        switch (choice)
        {
        case 0:
            return 0;

        case 1:
            cout<<"Enter the index of the vector \n->";
            cin>>index1;
            vect[index1-1]->print();
            break;

         case 2:
            cout<<"Enter the index of the vector \n->";
            cin>>index1;
            cout<<vect[(index1-1)]->getType();
            break;

        case 3:
            cout<<"Enter the index of the vector \n->";
            cin>>index1;
            (vect[(index1-1)]->unit())->print();

            break;

        case 4:
            cout<<"Enter the index of the vector \n->";
            cin>>index1;
            cout<<vect[(index1-1)]->mod();

            break;

        case 5:
            cout<<"Enter the indices of the vector \n->";
            cin>>index1>>index2;
            cout<<vect[(index1-1)]->dot(*(vect[(index2-1)]));

            break;

        case 6:
            cout<<"Enter the indices of the vector \n->";
            cin>>index1>>index2;
            (*vect[index1-1] * *vect[index2-1])->print();

            break;

        case 7:
            cout<<"Enter the indices of the vector \n->";
            cin>>index1>>index2;
            (*vect[index1-1] + *vect[index2-1])->print();

            break;

        case 8:
            cout<<"Enter the indices of the vector \n->";
            cin>>index1>>index2;
            (*vect[index1-1] - *vect[index2-1])->print();

            break;

        case 9:
            cout<<"Enter the index of the vector \n->";
            cin>>index1;
            ((*vect[(index1-1)])++)->print();

            break;

        case 10:
            cout<<"Enter the index of the vector \n->";
            cin>>index1;
            ++(*vect[(index1-1)]);
            vect[(index1-1)]->print();
            break;

         case 11:
            cout<<"Enter the indices of the vector \n->";
            cin>>index1>>index2;

            if(*vect[(index1-1)] == *vect[(index2-1)])
                cout<<"The vectors are equal";
            else
                cout<<"The vectors are not equal";

            break;

        default :
                cout<<"Invalid choice";
                break;
        }
        cout<<endl;
    }
}

