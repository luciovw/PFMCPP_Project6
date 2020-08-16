/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T

{
    T(int v, const char* n) : //1
    value(v),
    name(n)
    {
        
    }
    int value; //2
    std::string name; //3
};

struct CompareF                                //4
{
    T* compare(T* a, T* b) //5
    {
        if (a!= nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
            return nullptr;
        }
        return nullptr;
    }
};

struct U
{
    float val1 { 0 }, val2 { 0 };
    float valUpdate(float* updatedValue)      //12
    {
        if(updatedValue != nullptr)
        {
            std::cout << "U -> val1: " << val1 << std::endl;
            val1 = *updatedValue;
            std::cout << "U -> val1 updated: " << val1 << std::endl;

            while(std::abs(val2 - val1) > 0.001f)
            {
                val2 += 0.01f;
            }
            
            std::cout << "U -> val2 updated: " << val2 << std::endl;
            return val1 * val2;
        }
        return 0.0f;
    }
};

struct UU
{
    static float updateU(U* that, float* updatedValue )        //10
    {
        if(that != nullptr && updatedValue != nullptr)
        {
            std::cout << "U's val1 value: " << that->val1 << std::endl;
            that->val1 = *updatedValue;
            std::cout << "U's val1 updated value: " << that->val1 << std::endl;
            while( std::abs(that->val2 - that->val1) > 0.001f )
            {
                that->val2 += 0.01f;
            }
            std::cout << "U's val2 updated value: " << that->val2 << std::endl;
            return that->val2 * that->val1;
        }
        return 0.0f;
    }
};
        
/*
MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
         
Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
         
If you didn't already:
Make a pull request after you make your first commit
pin the pull request link and this repl.it link to our DM thread in a single message.
         
send me a DM to review your pull request when the project is ready for review.
         
Wait for my code review.
*/
        
int main()
{
    T obj1(5 , "obj1");                                             //6
    T obj2(25 , "obj2");                                             //6
            
    CompareF f; //7
    auto* smaller = f.compare(&obj1 , &obj2);//8
    if (smaller != nullptr)
    {
    std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
            
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << UU::updateU(&u1 , &updatedValue) << std::endl; //11
            
    U u2;
    std::cout << "[member func] u2s multiplied values: " << u2.valUpdate( &updatedValue ) << std::endl;
}
