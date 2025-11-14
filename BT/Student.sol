// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    // Structure to store student information
    struct Student {
        uint id;
        string name;
    }

    // Array to hold multiple students
    Student[] public students;
    uint public nextId = 0;

    // Events for Fallback and Ether reception
    event FallbackCalled(address sender, uint value);
    event EtherReceived(address sender, uint value);

    // Create a new student record
    function Create(string memory name) public {
        students.push(Student(nextId, name));
        nextId++;
    }

    // Read student data by ID
    function Read(uint id) public view returns (uint, string memory) {
        for (uint i = 0; i < students.length; i++) {
            if (students[i].id == id) {
                return (students[i].id, students[i].name);
            }
        }
        revert("Student not found");
    }

    // Update student name by ID
    function Update(uint id, string memory name) public {
        for (uint i = 0; i < students.length; i++) {
            if (students[i].id == id) {
                students[i].name = name;
                return;
            }
        }
        revert("Student not found");
    }

    // Delete a student record
    function Delete(uint id) public {
        uint index = find(id);
        delete students[index];
    }

    // Helper internal function to find a student index
    function find(uint id) internal view returns (uint) {
        for (uint i = 0; i < students.length; i++) {
            if (students[i].id == id) {
                return i;
            }
        }
        revert("Student does not exist");
    }

    receive() external payable {
        emit EtherReceived(msg.sender, msg.value);
    }


    fallback() external payable {
        emit FallbackCalled(msg.sender, msg.value);
    }
}
