#include<iostream>
#include<future>
int find_an_answer_()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    return 4;
}
void do_other_stuff()
{

}

int main()
{
    std::future<int> the_answer =std::async(find_an_answer_);
    do_other_stuff();
    std::cout<<"The answer is::"<<the_answer.get()<<std::endl;
}
