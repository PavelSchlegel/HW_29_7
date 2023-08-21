#include "list.hpp"
#include <iostream>
#include <assert.h>
#include <shared_mutex>

void FineGradientQueue::InsertIntoMidle(int value, int pos)
{
    assert(pos >= 1 && "Pos is negetiv value!");
    Node* new_node = new Node;
    new_node->s_value = value;
    std::unique_lock<std::mutex> M(*m_queue_mutex);
    if (m_head) {
        if (pos == 1) {
            new_node->s_next = m_head;
            m_head = new_node;
            return;
        }
        Node* rec = m_head;
        M.unlock();
        while (rec) {
            --pos;
            std::lock_guard T(*rec->s_node_mutex);
            if (pos == 0) {
                new_node->s_next->s_next = new_node;
                new_node->s_next = rec;
                return;
            }
            if (rec->s_next) {
                new_node->s_next = rec;
                rec = rec->s_next;
                continue;
            }
            rec->s_next = new_node;
            new_node->s_next = nullptr;
            return;
        }
    }
    m_head = new_node;
}


void FineGradientQueue::insert(int value)
{
    Node* new_node = new Node;
    new_node->s_value = value;
    Node* rec = m_head;
    while (rec) {
        //лог ноды
        std::lock_guard<std::mutex> M(*rec->s_node_mutex);
        if (rec->s_next) {
            rec = rec->s_next;
            continue;
        }
        rec->s_next = new_node;
        return;
    }
    //лог головы
    std::lock_guard<std::mutex> M(*this->m_queue_mutex);
    m_head = new_node;
}

void FineGradientQueue::FGQ_print() const
{
    Node* print = m_head;
    std::lock_guard M(*this->m_queue_mutex);
    while (print) {
        std::cout << print->s_value << " ";
        print = print->s_next;
    }
}