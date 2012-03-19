//#include "functional"
#include "vector"
#include "algorithm"
#include "iostream"

//Your class
class myclass
{
    public:
        int i;
        myclass():i(10){}
};


// Functor for deleting pointers in vector.
template<class T> class DeleteVector
{
    public:
        // Overloaded () operator.
        // This will be called by for_each() function.
        bool operator()(T x) const
        {
            // Delete pointer.
            delete x;
            return true;
        }
};


int main()
{
    // Add 10 objects to the vector.
    std::vector<myclass*> myclassVector;

    for( int Index = 0; Index < 10; ++Index )
    {
        myclassVector.push_back( new myclass);
    }

    for (int i=0; i<myclassVector.size(); i++) 
    {
        std::cout << " " << (myclassVector[i])->i;
    }

    // Now delete the vector contents in a single  line.
    for_each( myclassVector.begin(),
            myclassVector.end(),
            DeleteVector<myclass*>());

    //Clear the vector 
    myclassVector.clear();

    std::cout<<"\n"<<myclassVector.size();

    return 0;
}
