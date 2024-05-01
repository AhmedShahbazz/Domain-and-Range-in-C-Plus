#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

const int table_size=30;
const int a=37;

struct node
{
    string data;
    node *next=NULL;
    int count=0;
};

class hash_table
{
    node *array[table_size];
public:
    hash_table()
    {
        for(int i=0; i<table_size; i++)
        {
            array[i]=NULL;
        }
    }



    void insert_data(string key)
    {
        int x=0;
        x=hash_(key);
        //cout<<"hash code of "<<key <<"  is:"<<x<<endl;

        node *t=new node;
        t->data=key;

        if(array[x]==NULL)
        {
            //cout<<" empty "<<endl;
            array[x]=t;
        }
        else
        {
            node *temp=new node;
            temp=array[x];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=t;
        }
        array[x]->count++;
    }
    int hash_(string key)
    {
        unsigned long ASCII_Sum=0;
        for(int i=0; i<key.size(); i++)
        {
            ASCII_Sum+=key[i]*pow(a,i);
        }
        return ASCII_Sum%table_size;
    }
    void display()
    {
        for(int i=0; i<table_size; i++)
        {
            cout<<"At Index: "<<i<<"  ==>";
            {
                node *temp;
                temp=array[i];
                while(temp!=NULL)
                {
                    cout<<" => "<<temp->data;
                    temp=temp->next;
                }
                cout<<endl;
            }
        }
    }
    void read_data()
    {
        fstream newfile;

        newfile.open("filename.txt",ios::in);
        if (newfile.is_open())
        {
            string tp;
            while(newfile>> tp)
            {
                // cout<< tp<<endl;
                insert_data(tp);
            }
            newfile.close(); //close the file object.
        }

    }
    void collision()
    {
        int x=0;
        int y=0;
        int index;
        for(int i = 0; i < table_size; ++i)
        {
            // Change < to > if you want to find the smallest element
            if(array[i]!=NULL)
            {

                if(x < array[i]->count)
                {
                    x = array[i]->count;
                    index=i;
                }
                y=y+array[i]->count;
            }
        }
        node *temp=new node;
        temp=array[index];
        cout<<"At Index "<<index;
        while(temp!=NULL)
        {
            cout<<" => "<<temp->data;
            temp=temp->next;
        }
         cout<<"\nTotal Nodes are: "<<y<<endl;
    }
};
