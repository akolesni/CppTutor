#include "gtest/gtest.h"


struct BookStats
{
    std::string title;
    std::vector<std::string> authors;
    std::vector<std::string> tags;
    unsigned pageCount = 0U;
    unsigned publishingYear = 0U;
};

TEST(TestStruct, testStruct_memberInitializing_successful)
{
    BookStats bookStats;
    ASSERT_EQ(0U, bookStats.pageCount);
    ASSERT_EQ(0U, bookStats.publishingYear);
}

TEST(TestStruct, testStruct_memberScopeInitializing_successful)
{
    const auto book = BookStats{
            u8"Clean code",
            { u8"Uncle Bob" },
            { u8"fun", u8"sign fiction" },
            576,
            1965
    };
    ASSERT_EQ(2U, book.tags.size());
    ASSERT_EQ(576U, book.pageCount);
    ASSERT_EQ(1965U, book.publishingYear);
}

TEST(TestStruct, testStruct_namedMemberScopeInitializing_successful)
{
    const auto book = BookStats{
            .title = u8"Clean code",
            .authors = { u8"Uncle Bob" },
            .tags = { u8"fun", u8"sign fiction" },
            .pageCount = 576,
            .publishingYear = 1965
    };
    ASSERT_EQ(2U, book.tags.size());
    ASSERT_EQ(576U, book.pageCount);
    ASSERT_EQ(1965U, book.publishingYear);
}

TEST(TestStruct, testStruct_namedMemberScopeInitializingColon_successful)
{
    const auto book = BookStats{
            title : u8"Clean code",
            authors : { u8"Uncle Bob" },
            tags : { u8"fun", u8"sign fiction" },
            pageCount : 576,
    };
    ASSERT_EQ(2U, book.tags.size());
    ASSERT_EQ(576U, book.pageCount);
    ASSERT_EQ(0U, book.publishingYear);
}

/* C++ 20
 * C++ 14 sorry, unimplemented: non-trivial designated initializers not supported
 * C++ 17 error: designator order for field 'BookStats::pageCount' does not match declaration order in 'BookStats'
TEST(TestStruct, testStruct_namedMemberScopeInitializingColonNotOrdered_successful)
{
    const auto book = BookStats{
            publishingYear : 1965,
            title : u8"Clean code",
            authors : { u8"Uncle Bob" },
            tags : { u8"fun", u8"sign fiction" },
            pageCount : 576
    };
    ASSERT_EQ(2U, book.tags.size());
    ASSERT_EQ(576U, book.pageCount);
    ASSERT_EQ(1965U, book.publishingYear);
}


TEST(TestStruct, testStruct_namedMemberScopeInitializingNotOrdered_successful)
{
    const auto book = BookStats{
            .publishingYear = 1965,
            .pageCount = 576,
            .tags = { u8"fun", u8"sign fiction" },
            .authors = { u8"Uncle Bob" },
            .title = u8"Clean code"
    };
    ASSERT_EQ(2U, book.tags.size());
    ASSERT_EQ(576U, book.pageCount);
    ASSERT_EQ(1965U, book.publishingYear);
}
*/


TEST(TestStruct, testStruct_structuredBinding_successful)
{
    const auto book = BookStats{
            u8"Clean code",
            { u8"Uncle Bob" },
            { u8"fun", u8"sign fiction" },
            576,
            1965
    };

    // struct decomposit
    const auto [title, authors, tags, pagesCount, publishingYear] = book;

    ASSERT_EQ(title, book.title);
    ASSERT_EQ(authors, book.authors);
    ASSERT_EQ(tags, book.tags);
    ASSERT_EQ(pagesCount, book.pageCount);
    ASSERT_EQ(publishingYear, book.publishingYear);
}

TEST(TestStruct, testTuple_tupleDecomposit_successful)
{
    std::tuple<BookStats, int, std::vector<double>, std::string> tuple =
            {
                    {
                            u8"Clean code",
                            { u8"Uncle Bob" },
                            { u8"fun", u8"sign fiction" },
                            576,
                            1965
                    },
                    -42,
                    {-0.54, 100.0, 0.0},
                    "Hallo world!"
            };
    // tuple decomposit
    const auto& [book, intValue, v, strValue] = tuple;

    ASSERT_EQ(book.title, std::get<0>(tuple).title);
    ASSERT_EQ(intValue, std::get<1>(tuple));
    ASSERT_EQ(v, std::get<2>(tuple));
    ASSERT_EQ(strValue, std::get<3>(tuple));
}
