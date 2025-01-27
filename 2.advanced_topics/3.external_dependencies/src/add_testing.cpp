// Copyright (c) 2023 HolyGround, All Rights Reserved.
// Authors: EunSung Yang

#include <cstdint>

#include "gtest/gtest.h"

auto Add(int32_t lhs, int32_t rhs) -> int32_t { return lhs + rhs; }

TEST(external_dependencies, Add) { EXPECT_EQ(Add(1, 2), 3); }

auto main(int32_t argc, char **argv) -> int32_t {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
