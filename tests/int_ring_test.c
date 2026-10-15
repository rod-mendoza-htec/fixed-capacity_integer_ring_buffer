#include "unity.h"
#include "int_ring.h"

IntRing ring;

void setUp(void){
    int_ring_init(&ring);
}
void tearDown(void){}

void test_1(void){
    TEST_ASSERT_TRUE(int_ring_is_empty(&ring));
}

void test_2(void){
    int valor;

    int_ring_push(&ring, 1);
    TEST_ASSERT_EQUAL(1, int_ring_size(&ring));
    TEST_ASSERT_FALSE(int_ring_is_empty(&ring));
    TEST_ASSERT_EQUAL(1, int_ring_peek(&ring, &valor));
    int_ring_pop(&ring, &valor);
    TEST_ASSERT_TRUE(int_ring_is_empty(&ring));
    

}

void test_init(void){
    TEST_ASSERT_TRUE(int_ring_is_empty(&ring));
}

void test_push(void){
    int_ring_push(&ring, 10);
    TEST_ASSERT_EQUAL(10, ring.data[0]);
}

void test_push2(void){
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    TEST_ASSERT_FALSE(int_ring_push(&ring, 1));
}

void test_size(void){
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);

    TEST_ASSERT_EQUAL(2, ring.size);
}

void full(void){
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 1);
    //TEST_ASSERT_EQUAL(4, ring.size);
    TEST_ASSERT_TRUE(int_ring_is_full(&ring));
}

void empty(void){
    int_ring_push(&ring, 1);
    int_ring_push(&ring, 2);
    
    TEST_ASSERT_FALSE(int_ring_is_empty(&ring));
}

void pop(void){
    int valor;
    TEST_ASSERT_FALSE(int_ring_peek(&ring, &valor));

    int_ring_push(&ring, 1);
    int_ring_push(&ring, 2);
    int_ring_pop(&ring, &valor);
    TEST_ASSERT_EQUAL(1, int_ring_size(&ring));
    int_ring_pop(&ring, &valor);
    TEST_ASSERT_TRUE(int_ring_is_empty(&ring));
}

void peek(void){
    int valor;
    TEST_ASSERT_FALSE(int_ring_peek(&ring, &valor));

    int_ring_push(&ring, 1);
    int_ring_push(&ring, 2);
    

    int_ring_peek(&ring, &valor);
    TEST_ASSERT_EQUAL(1, valor);
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_1);
    RUN_TEST(test_2);
    RUN_TEST(test_init);
    RUN_TEST(test_push);
    RUN_TEST(test_push2);
    RUN_TEST(test_size);
    RUN_TEST(full);
    RUN_TEST(empty);
    RUN_TEST(pop);
    RUN_TEST(peek);
    return UNITY_END();
}

