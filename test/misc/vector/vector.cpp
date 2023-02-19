#include <gtest/gtest.h>

extern "C" {
#include <misc/vector/vector.h>
}

TEST(vector, build_vector) {
  struct Vec vec;

  vec_build(&vec);

  ASSERT_EQ(vec.size, 0);
  ASSERT_EQ(vec.capacity, 0);

  vec_destroy(&vec);
}


TEST(vector, clear_vector) {
  struct Vec vec;

  vec_build(&vec);
  vec_destroy(&vec);

  ASSERT_EQ(vec.capacity, 0);
  ASSERT_EQ(vec.size, 0);
}

TEST(vector, vector_push_one_element) {
  struct Vec vec;
  char elt = 'g';

  vec_build(&vec);
  ASSERT_EQ(vec_push(&vec, elt), 0);

  ASSERT_EQ(vec.size, 1);
  ASSERT_EQ(vec.capacity, 8);
  ASSERT_EQ(elt, vec.data[0]);

  vec_destroy(&vec);
}

TEST(vector, vector_fill_capacity) {
    struct Vec vec;
    char elt_1 = 'v';
    char elt_2 = 'o';
    char elt_3 = 'a';
    char elt_4 = 'f';
    char elt_5 = 'c';
    char elt_6 = 'd';
    char elt_7 = 't';
    char elt_8 = 'e';

    vec_build(&vec);

  ASSERT_EQ(vec_push(&vec, elt_1), 0);
    ASSERT_EQ(vec_push(&vec, elt_2), 0);
    ASSERT_EQ(vec_push(&vec, elt_3), 0);
    ASSERT_EQ(vec_push(&vec, elt_4), 0);
    ASSERT_EQ(vec_push(&vec, elt_5), 0);
    ASSERT_EQ(vec_push(&vec, elt_6), 0);
    ASSERT_EQ(vec_push(&vec, elt_7), 0);
    ASSERT_EQ(vec_push(&vec, elt_8), 0);

    ASSERT_EQ(vec.size, 8);
    ASSERT_EQ(vec.capacity, 8);
    ASSERT_EQ(elt_1, vec.data[0]);
    ASSERT_EQ(elt_2, vec.data[1]);
    ASSERT_EQ(elt_3, vec.data[2]);
    ASSERT_EQ(elt_4, vec.data[3]);
    ASSERT_EQ(elt_5, vec.data[4]);
    ASSERT_EQ(elt_6, vec.data[5]);
    ASSERT_EQ(elt_7, vec.data[6]);
    ASSERT_EQ(elt_8, vec.data[7]);

    vec_destroy(&vec);
}

TEST(vector, vector_fill_to_expand) {
  struct Vec vec;
  char elt_1 = 'v';
  char elt_2 = 'o';
  char elt_3 = 'a';
  char elt_4 = 'f';
  char elt_5 = 'c';
  char elt_6 = 'd';
  char elt_7 = 't';
  char elt_8 = 'e';
  char elt_9 = 'p';

  vec_build(&vec);

  ASSERT_EQ(vec_push(&vec, elt_1), 0);
  ASSERT_EQ(vec_push(&vec, elt_2), 0);
  ASSERT_EQ(vec_push(&vec, elt_3), 0);
  ASSERT_EQ(vec_push(&vec, elt_4), 0);
  ASSERT_EQ(vec_push(&vec, elt_5), 0);
  ASSERT_EQ(vec_push(&vec, elt_6), 0);
  ASSERT_EQ(vec_push(&vec, elt_7), 0);
  ASSERT_EQ(vec_push(&vec, elt_8), 0);
  ASSERT_EQ(vec_push(&vec, elt_9), 0);

  ASSERT_EQ(vec.size, 9);
  ASSERT_EQ(vec.capacity, 16);
  ASSERT_EQ(elt_1, vec.data[0]);
  ASSERT_EQ(elt_2, vec.data[1]);
  ASSERT_EQ(elt_3, vec.data[2]);
  ASSERT_EQ(elt_4, vec.data[3]);
  ASSERT_EQ(elt_5, vec.data[4]);
  ASSERT_EQ(elt_6, vec.data[5]);
  ASSERT_EQ(elt_7, vec.data[6]);
  ASSERT_EQ(elt_8, vec.data[7]);
  ASSERT_EQ(elt_9, vec.data[8]);

  vec_destroy(&vec);
}

TEST(vector, vector_push_str_to_fill_no_expand) {
  struct Vec vec;
  char expected[] = "Password";

  vec_build(&vec);
  ASSERT_EQ(vec_push_str(&vec, expected, strlen(expected)), 0);

  ASSERT_EQ(vec.size, 8);
  ASSERT_EQ(vec.capacity, 8);
  ASSERT_EQ(strncmp(expected, vec.data, 8), 0);

  vec_destroy(&vec);
}

TEST(vector, vector_push_str_to_expand) {
  struct Vec vec;
  char expected[] = "Technique";

  vec_build(&vec);
  ASSERT_EQ(vec_push_str(&vec, expected, strlen(expected)), 0);

  ASSERT_EQ(vec.size, strlen(expected));
  ASSERT_EQ(vec.capacity, 16);
  ASSERT_EQ(strncmp(expected, vec.data, strlen(expected)), 0);

  vec_destroy(&vec);
}

TEST(vector, vector_push_long_str) {
  struct Vec vec;
  char expected[] = "dapibus ultrices in iaculis nunc sed augue lacus viverra vitae congue eu consequat ac felis donec et odio pellentesque diam volutpat commodo sed egestas egestas fringilla phasellus faucibus scelerisque eleifend donec pretium vulputate sapien nec sagittis aliquam malesuada bibendum arcu vitae elementum curabitur vitae nunc sed velit dignissim sodales ut eu sem integer vitae justo eget magna fermentum iaculis eu non diam phasellus vestibulum lorem sed risus ultricies tristique nulla aliquet enim tortor at auctor urna nunc id cursus metus aliquam eleifend mi in nulla posuere sollicitudin aliquam ultrices sagittis orci a scelerisque purus semper eget duis at tellus at urna condimentum mattis pellentesque id nibh tortor id aliquet lectus proin nibh nisl condimentum id venenatis a condimentum vitae sapien pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas sed tempus urna et pharetra pharetra massa massa ultricies mi quis hendrerit dolor magna eget est lorem ipsum dolor sit amet consectetur adipiscing elit pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas integer eget aliquet nibh praesent tristique magna sit amet purus gravida quis blandit turpis cursus in hac habitasse platea dictumst quisque sagittis purus sit amet volutpat consequat mauris nunc congue nisi vitae suscipit tellus mauris a diam maecenas sed enim ut sem viverra aliquet eget sit amet tellus cras adipiscing enim eu turpis egestas pretium aenean pharetra magna ac placerat vestibulum lectus mauris ultrices eros in cursus turpis massa tincidunt dui ut ornare lectus sit amet est placerat in egestas erat imperdiet sed euismod nisi porta lorem mollis aliquam ut porttitor leo a diam sollicitudin tempor id eu nisl nunc mi ipsum faucibus vitae aliquet nec ullamcorper sit amet risus nullam eget felis eget nunc lobortis mattis aliquam faucibus purus in massa tempor nec feugiat nisl pretium fusce id velit ut tortor pretium viverra suspendisse potenti nullam ac tortor vitae purus faucibus ornare suspendisse sed nisi lacus sed viverra tellus in hac habitasse platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper dignissim cras tincidunt lobortis feugiat vivamus at augue eget arcu dictum varius duis at consectetur lorem donec massa sapien faucibus et molestie ac feugiat sed lectus vestibulum mattis ullamcorper velit sed ullamcorper morbi tincidunt ornare massa eget egestas purus viverra accumsan in nisl nisi scelerisque eu ultrices vitae auctor eu augue ut lectus arcu bibendum at varius vel pharetra vel turpis nunc eget lorem dolor sed viverra ipsum nunc aliquet bibendum enim facilisis gravida neque convallis a cras semper auctor neque vitae tempus quam pellentesque nec nam aliquam sem et tortor consequat id porta nibh venenatis cras sed felis eget velit aliquet sagittis id consectetur purus ut faucibus pulvinar elementum integer enim neque volutpat ac tincidunt vitae semper quis lectus nulla at volutpat diam ut venenatis tellus in metus vulputate eu scelerisque felis imperdiet proin fermentum leo vel orci porta non pulvinar neque laoreet suspendisse interdum consectetur libero id faucibus nisl tincidunt eget nullam non nisi est sit amet facilisis magna etiam tempor orci eu lobortis elementum nibh tellus molestie nunc non blandit massa enim nec dui nunc mattis enim ut tellus elementum sagittis vitae et leo duis ut diam quam nulla porttitor massa id neque aliquam vestibulum morbi blandit cursus risus at ultrices mi tempus imperdiet nulla malesuada pellentesque elit eget gravida cum sociis natoque penatibus et magnis dis parturient montes nascetur ridiculus mus mauris vitae ultricies leo integer malesuada nunc vel risus commodo viverra maecenas accumsan lacus vel facilisis volutpat est velit egestas dui id ornare arcu odio ut sem nulla pharetra diam sit amet nisl suscipit adipiscing bibendum est ultricies integer quis auctor elit sed vulputate mi sit amet mauris commodo quis imperdiet massa tincidunt nunc pulvinar sapien et ligula ullamcorper malesuada proin libero nunc consequat interdum varius sit amet mattis vulputate enim nulla aliquet porttitor lacus luctus accumsan tortor posuere ac ut consequat semper viverra nam libero justo laoreet sit amet cursus sit amet dictum sit amet justo donec enim diam vulputate ut pharetra sit amet aliquam id diam maecenas ultricies mi eget mauris pharetra et ultrices neque ornare aenean euismod elementum nisi quis eleifend quam adipiscing vitae proin sagittis nisl rhoncus mattis rhoncus urna neque viverra justo nec ultrices dui sapien eget mi proin sed libero enim sed faucibus turpis in eu mi bibendum neque egestas congue quisque egestas diam in arcu cursus euismod quis viverra nibh cras pulvinar mattis nunc sed blandit libero volutpat sed cras ornare arcu dui vivamus arcu felis bibendum ut tristique et egestas quis ipsum suspendisse ultrices gravida dictum fusce ut placerat orci nulla pellentesque dignissim enim sit amet venenatis urna cursus eget nunc scelerisque viverra mauris in aliquam sem fringilla ut morbi tincidunt augue interdum velit euismod in pellentesque massa placerat duis ultricies lacus sed turpis tincidunt id aliquet risus feugiat in ante metus dictum at tempor commodo ullamcorper a lacus vestibulum sed arcu non odio euismod lacinia at quis risus sed vulputate odio ut enim blandit volutpat maecenas volutpat blandit aliquam etiam erat velit scelerisque in dictum non consectetur a erat nam at lectus urna duis convallis convallis tellus id interdum velit laoreet id donec ultrices tincidunt arcu non sodales neque sodales ut etiam sit amet nisl purus in mollis nunc sed id semper risus in hendrerit gravida rutrum quisque non tellus orci ac auctor augue mauris augue neque gravida in fermentum et sollicitudin ac orci phasellus egestas tellus rutrum tellus pellentesque eu tincidunt tortor aliquam nulla facilisi cras fermentum odio eu feugiat pretium nibh ipsum consequat nisl vel pretium lectus quam id leo in vitae turpis massa sed elementum tempus egestas sed sed risus pretium quam vulputate dignissim suspendisse in est ante in nibh mauris cursus mattis molestie a iaculis at erat pellentesque adipiscing commodo elit at imperdiet dui accumsan sit amet nulla facilisi morbi tempus iaculis urna id volutpat lacus laoreet non curabitur gravida arcu ac tortor dignissim convallis aenean et tortor at risus viverra adipiscing at in tellus integer feugiat scelerisque varius morbi enim nunc faucibus a pellentesque sit amet porttitor eget dolor";

  vec_build(&vec);
  ASSERT_EQ(vec_push_str(&vec, expected, strlen(expected)), 0);

  ASSERT_EQ(vec.size, strlen(expected));
  ASSERT_EQ(vec.capacity, 16);
  ASSERT_EQ(strncmp(expected, vec.data, strlen(expected)), 0);

  vec_destroy(&vec);
}
