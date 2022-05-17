#include <gtest/gtest.h>

extern "C" {
#include"../project_function.h"
}
namespace {
    class PatternGenerator : public ::testing::Test {

    protected:
        PatternGenerator() {
        }

        ~PatternGenerator() override = default;

        void SetUp() override {
            widget_test = static_cast<MyWidget *>(malloc(sizeof(MyWidget)));
            widget_test->row_entry_input = gtk_entry_new();
            widget_test->col_entry_input = gtk_entry_new();
            gtk_entry_set_text(GTK_ENTRY(widget_test->row_entry_input), "4");
            gtk_entry_set_text(GTK_ENTRY(widget_test->col_entry_input), "4");
        }

        void TearDown() override {
            free(widget_test);
        }

        MyWidget *widget_test{};
    };

    TEST_F(PatternGenerator, case_1) {
        create_view2(widget_test);
        EXPECT_EQ(widget_test->col, 2);
        ASSERT_EQ(widget_test->row, 2);
    }

    TEST_F(PatternGenerator, case_2) {
        get_row_entry_input(nullptr, widget_test);
        get_col_entry_input(nullptr, widget_test);
        int expected = 4;
        EXPECT_EQ(widget_test->row, expected);
        EXPECT_EQ(widget_test->col, expected);
    }

    TEST_F(PatternGenerator, case_3) {
        get_row_entry_input(nullptr, widget_test);
        get_col_entry_input(nullptr, widget_test);
        create_view1(widget_test);
        int expected = 4;
        create_view2(widget_test);
        EXPECT_EQ(widget_test->row, expected);
        EXPECT_EQ(widget_test->col, expected);
    }

}

int main(int argc, char **argv) {
    gtk_init(&argc, &argv);
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
/*
 *
namespace {

    class MyTestFixture : public ::testing::Test {
    protected:
        MyTestFixture() : sbuf{nullptr} {
            // intentionally empty
        }

        ~MyTestFixture() override = default;

        // Called before each unit test
        void SetUp() override {
            // Save cout's buffer...
            sbuf = std::cout.rdbuf();
            // Redirect cout to our stringstream buffer or any other ostream
            std::cout.rdbuf(buffer.rdbuf());
        }

        // Called after each unit test
        void TearDown() override {
            // When done redirect cout to its old self
            std::cout.rdbuf(sbuf);
            sbuf = nullptr;
        }
        // The following objects can be reused in each unit test

        // This can be an ofstream as well or any other ostream
        std::stringstream buffer{};
        // Save cout's buffer here
        std::streambuf *sbuf;
    };
}

 */