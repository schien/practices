#!/bin/sh

usage() {
  echo "usage: ./create_project.sh new-project-name"
  exit 1
}

if [ -z $1 ]; then
  usage
fi

project_name=$1
underscore_name="${project_name//\-/_}"
camel_case_name="$(perl -pe 's/(^|-)(\w)/\U$2/g' <<< $project_name)"

prj_folder="src/$project_name"
cmakelists_file="$prj_folder/CMakeLists.txt"
main_file="$prj_folder/main.cpp"
test_file="$prj_folder/test.cpp"
solution_file="$prj_folder/solution.cpp"

if [ ! -d "$prj_folder" ]; then
  mkdir $prj_folder
fi

template_cmakelists="template/CMakeLists.txt.in"
template_main="template/main.cpp.in"
template_test="template/test.cpp.in"

sed -e "s/##PROJECT_NAME##/$project_name/g;s/##UNDERSCORE_NAME##/$underscore_name/g" $template_cmakelists > $cmakelists_file

cp $template_main $main_file

sed -e "s/##CAMEL_CASE_NAME##/$camel_case_name/g" $template_test > $test_file

touch $solution_file

printf "add_subdirectory(%s)\n" $prj_folder >> CMakeLists.txt

printf "create %s\n" $prj_folder
