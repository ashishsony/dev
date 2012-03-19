#include<algorithm>
template <typename T>
class deleteVectorPtr
{
    void operator()(T x)
    {
        delete x;
    }
};
vector<myclass*> Vec;
for_each(Vec.begin(),Vec.end(),deleteVectorPtr<myclass*>());
