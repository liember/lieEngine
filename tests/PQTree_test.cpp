//
// Created by liember on 1/21/21.
//

#include "gtest/gtest.h"
#include "base_object.hpp"
#include "base_object.hpp"
#include "PQTree.h"

using namespace lieEngine::core;

TEST(PQTree, init) {
    lieEngine::core::space::PQTree<double, lieEngine::core::base_object> tree(2, 20);
    ASSERT_EQ(2, tree.deep_limit);
    ASSERT_EQ(40, tree.tree_root->sideSize());
}

TEST(PQTree_Node, init) {
    space::PQTree_node<double, double> node(nullptr, 10, 0, 0);
    ASSERT_TRUE(node.objects.empty());
    ASSERT_TRUE(node.childs.empty());
}

TEST(PQTree_Node, hard_insert) {
    space::PQTree_node<double, double> node(nullptr, 10, 0, 0);
    node.hard_insert({1, 1}, new double(2));
    ASSERT_TRUE(!node.objects.empty());
    ASSERT_TRUE(node.childs.empty());
    ASSERT_EQ(*node.objects.begin()->second, 2);
}

TEST(PQTree_Node, simple_insert) {
    space::PQTree_node<double, double> node(nullptr, 10, 0, 0);
    node.insert(5, 0, 4, {1, 1}, new double(2));
    ASSERT_TRUE(!node.objects.empty());
    ASSERT_TRUE(node.childs.empty());
    ASSERT_EQ(*node.objects.begin()->second, 2);
}

TEST(PQTree_Node, multiply_insert) {
    space::PQTree_node<double, double> node(nullptr, 10, 0, 0);
    node.insert(5, 0, 1, {1, 1}, new double(2));
    node.insert(5, 0, 1, {6, 6}, new double(3));
    ASSERT_TRUE(node.objects.empty());
    ASSERT_TRUE(!node.childs.empty());
    ASSERT_EQ(*node.childs.begin()->objects.begin()->second, 3);
    auto val = (node.childs.begin() + 2)->objects.begin()->second;
    ASSERT_EQ(*val, 2);
}

TEST(PQTree, simple_insert) {
    lieEngine::core::space::PQTree<double, double> tree(2, 20);
    tree.insert({1, 1}, new double(12));
    ASSERT_TRUE(tree.tree_root != nullptr);
    ASSERT_FALSE(tree.tree_root->objects.empty());
    ASSERT_TRUE(tree.tree_root->childs.empty());
    auto el = tree.tree_root->objects.begin()->second;
    ASSERT_EQ(12, *el);
}

TEST(PQTree_base_test, multiply_insert) {
    lieEngine::core::space::PQTree<double, double> tree(2, 20);
    tree.insert({1, 1}, new double(12)); //   [1] [3]
    tree.insert({1, 15}, new double(13)); //  [1] [2]
    tree.insert({15, 15}, new double(14)); // [1] [1]
    tree.insert({15, 1}, new double(15)); //  [1] [4]
    tree.insert({5, 5}, new double(16)); //   [1] [3]

    ASSERT_TRUE(tree.tree_root != nullptr);
    ASSERT_TRUE(tree.tree_root->objects.empty());
    ASSERT_FALSE(tree.tree_root->childs.empty());
    ASSERT_FALSE(tree.tree_root->childs.begin()->childs.empty());

    auto els = tree.tree_root->childs.begin()->childs;
    ASSERT_EQ(14, *els.begin()->objects.begin()->second);
    ASSERT_EQ(13, *(els.begin() + 1)->objects.begin()->second);
    ASSERT_EQ(12, *(els.begin() + 2)->objects.begin()->second);
    ASSERT_EQ(16, *((els.begin() + 2)->objects.begin() + 1)->second);
    ASSERT_EQ(15, *(els.begin() + 3)->objects.begin()->second);
}


