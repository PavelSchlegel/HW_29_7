#ifndef LIST_THREAD
#define LIST_THREAD
#include <mutex>
#include <thread>

struct Node
{
    int s_value;
    Node* s_next = nullptr;
    std::mutex* s_node_mutex;
    Node() {
        s_node_mutex = new std::mutex;
    }
    ~Node() {
        delete s_node_mutex;
    }
};

class FineGradientQueue
{
    Node* m_head = nullptr;
    std::mutex* m_queue_mutex;
public:
    FineGradientQueue() {
        m_queue_mutex = new std::mutex;
    }
    ~FineGradientQueue() {
        Node* node = m_head;
        while (node) {
            Node* del = node; 
            node = del->s_next;
            delete del;
        }
        delete m_queue_mutex;
    }

    void InsertIntoMidle(int value, int pos);
    void insert(int value);
    void FGQ_print() const;
};
#endif