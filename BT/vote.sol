// SPDX-License-Identifier: MIT

pragma solidity ^0.5.16;
// Command Line Help
// ctrl+d to exit console.
//web3.eth.getAccounts()
//web3.eth.getAccounts().then(function(acc) (account - acc})
contract Election{
    //Model a Candidate ID, Name and Vote Count
    struct Candidate {
        uint id;
        string name;
        uint voteCount;
    }
    // Store accounts that have voted
    mapping (address => bool) public voters;

    // Store candidate
    // Fetch candidate using mapping key/value pair
    mapping(uint => Candidate) public candidates;
    // Store Candidates Count this will be an index
    uint public candidatesCount;
    event votedEvent (
        uint indexed candidateId
    );
    // Constructor initialize state variables
    constructor() public {
    // Initialize candidate names
        addCandidate("Candidate 1");
        addCandidate("Candidate 2");
    }

    function addCandidate(string memory _name) private {
    // Increment vote count
    candidatesCount++;
    // create mapping
    candidates[candidatesCount] = Candidate(candidatesCount, _name, 0);
    }
    // Voting function
    function vote (uint _candidateId) public {
    // require that they have not voted before the voter account doesn't already exist in mapping
    require(!voters[msg.sender]);

    // require a valid candidate
    require(_candidateId > 0 && _candidateId <= candidatesCount);

    // record that voter has voted
    voters[msg.sender] = true;

    // update candidate vote count
    candidates[_candidateId].voteCount++;

    // trigger voted event
    emit votedEvent(_candidateId);
    }
}



//solcjs --bin --abi 4_Student.sol