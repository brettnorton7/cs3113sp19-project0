#!/usr/bin/env bats

TEST=`cat <<EOF
this is project 0 test case for oucat
EOF
`

TEST1=`cat <<EOF

EOF
`
TEST2=`cat <<EOF
this is project0
EOF
`

TEST3=`cat <<EOF
Test case for ouhead Project 0
EOF
`

TEST4=`cat <<EOF
}
EOF
`

TEST5=`cat <<EOF
7
EOF
`

TEST6=`cat <<EOF
3
4
5
6
7
EOF
`

TEST7=`cat <<EOF
      19
EOF
`

@test "oucat" {
  result="$(echo this is project 0 test case for oucat | ./oucat)"
  [ "$result" = "$TEST" ]
}

@test "ouecho 1" {
  result1="$(./ouecho)"
  [ "$result1" = "$TEST1" ]
}

@test "ouecho 2" {
  result2="$(./ouecho this is project0)"
  [ "$result2" = "$TEST2" ]
}

@test "ouhead" {
  result3="$(echo Test case for ouhead Project 0 | ./ouhead -n 1)"
  [ "$result3" = "$TEST3" ]
}


@test "outail" {
  result4="$(./outail -n 1 test_project0.bats)"
  [ "$result4" = "$TEST4" ]
}

@test "ouseq 1" {
  result5="$(./ouseq 7 7)"
  [ "$result5" = "$TEST5" ]
}

@test "ouseq 2" {
  result6="$(./ouseq 3 7)"
  [ "$result6" = "$TEST6" ]
}

@test "ouwc" {
  result7="$(echo test case for ouwc | ./ouwc -c)"
  [ "$result7" = "$TEST7" ]
}
