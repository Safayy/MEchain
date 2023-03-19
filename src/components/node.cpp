class Node {
public:
    Node(std::string address, int port) {
        // Initialize the node with the given address and port
    }

    void connectToNetwork(std::string bootstrapNodeAddress, int bootstrapNodePort) {
        // Connect to the bootstrap node using its address and port
        // Send a message to the bootstrap node to request a list of other nodes in the network
        // Connect to the other nodes in the list
    }

    void synchronizeBlock(){
        
    }

    void sendMessage(std::string message) {
        // Send a message to the connected nodes
    }

    void receiveMessage(std::string message) {
        // Handle incoming messages from other nodes
    }

private:
    std::string address;
    int port;
    std::vector<Node*> connectedNodes;
};
