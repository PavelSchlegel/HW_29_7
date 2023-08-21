#include "./list/list.hpp"

int main()
{
    FineGradientQueue A;
    A.insert(1);
    A.insert(2);
    A.insert(3);
    A.insert(4);
    // std::thread F(&FineGradientQueue::insert, &A, 8);
    std::thread T(&FineGradientQueue::InsertIntoMidle, &A, 5, 1);
    std::thread M(&FineGradientQueue::InsertIntoMidle, &A, 7, 3);
    // std::thread X(&FineGradientQueue::FGQ_print, &A);
    // A.InsertIntoMidle(5, 6);
    // F.join();
    T.join();
    M.join();
    A.FGQ_print();
    // X.join();
    return 0;
}