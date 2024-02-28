cmake_minimum_required(VERSION 3.24)
project(jobSearch1)

set(CMAKE_CXX_STANDARD 23)

add_executable(jobSearch1 main.cpp Employer.cpp Employer.h Candidate.cpp Candidate.h Apply.cpp Apply.h Job.cpp Job.h ManagementSystem.cpp ManagementSystem.h)
