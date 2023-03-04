#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stdio.h>

#define _USE_MATH_DEFINES

using namespace std;

class Shape
{
protected:
    string mShape;
    float mArea;
public:
    virtual void print()=0;
    virtual void calculateArea()=0;
    float getArea()
    {
        return mArea;
    }
};

class Square : public Shape
{
private:
    float mLength;
public:
    Square()
    {
        mLength=0;
        mArea=0;
        mShape="nedefinit";
    }
    Square(float arg_mLength)
    {
        mLength=arg_mLength;
        mShape="patrat";
    }
    void calculateArea()
    {
        mArea=mLength*mLength;
    }
    void print()
    {
        printf("%s %.2lf\n",mShape.c_str(),mLength);
    }
};

class Rectangle : public Shape
{
private:
    float mLength;
    float mWidth;
public:
    Rectangle()
    {
        mLength=0;
        mArea=0;
        mWidth=0;
        mShape="nedefinit";
    }
    Rectangle(float arg_mLength,float arg_mWidth)
    {
        mLength=arg_mLength;
        mWidth=arg_mWidth;
        mShape="dreptunghi";
    }
    void calculateArea()
    {
        mArea=mLength*mWidth;
    }
    void print()
    {
        printf("%s %.2lf %.2lf\n",mShape.c_str(),mLength,mWidth);
    }
};

class Circle : public Shape
{
private:
    float mRadius;
public:
    Circle()
    {
        mRadius=0;
        mArea=0;
        mShape="nedefinit";
    }
    Circle(float arg_mRadius)
    {
        mRadius=arg_mRadius;
        mShape="cerc";
    }
    void calculateArea()
    {
        mArea=mRadius*mRadius*M_PI;
    }
    void print()
    {
        printf("%s %.2lf\n",mShape.c_str(),mRadius);
    }
};

 bool comparator(Shape*s1,Shape*s2)
 {
     return s1->getArea() > s2->getArea();
 }

int main()
{
    int N;
    cin>>N;
    vector<Shape*>forme;
    for(int i=0;i<N;i++)
    {
        string nume;
        cin>>nume;
        if(nume=="patrat")
        {
            float latura;
            cin>>latura;
            forme.push_back(new Square(latura));
        }
        if(nume=="dreptunghi")
        {
            float lungime,latime;
            cin>>lungime>>latime;
            forme.push_back(new Rectangle(lungime,latime));
        }
        if(nume=="cerc")
        {
            float raza;
            cin>>raza;
            forme.push_back(new Circle(raza));
        }
    }
    for(int i=0;i<N;i++)
    {
        forme[i]->calculateArea();
    }
    sort(forme.begin(),forme.end(),comparator);
    for(int i=0;i<N;i++)
    {
        forme[i]->print();
    }
}
