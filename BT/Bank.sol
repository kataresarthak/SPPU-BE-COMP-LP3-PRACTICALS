// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract SimpleBank {
    mapping(address => uint256) private balances;
    
    // Deposit ETH into the bank
    function deposit() public payable {
        require(msg.value > 0, "Deposit must be greater than 0");
        balances[msg.sender] += msg.value;
    }

    // Withdraw ETH from the bank
    function withdraw(uint256 amountInEther) public {
        uint256 amount = amountInEther * 1 ether; // convert Ether to Wei
        require(amount <= balances[msg.sender], "Insufficient balance");
        
        balances[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);
    }

    // Return user balance in Ether
    function getBalance() public view returns (uint256) {
        return balances[msg.sender] / 1 ether;
    }

    // Return total contract balance in Ether
    function getBankBalance() public view returns (uint256) {
        return address(this).balance / 1 ether;
    }

    // Allow direct ETH transfers
    receive() external payable {
        balances[msg.sender] += msg.value;
    }
}
