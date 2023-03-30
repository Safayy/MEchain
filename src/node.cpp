// #include <iostream>
// #include <string>
// #include <boost/asio.hpp>
// #include <boost/thread.hpp>
// #include <boost/bind.hpp>
// #include "block.cpp"

// using boost::asio::ip::tcp;

// class Node {
// public:
//     Node(std::string ip_address, unsigned short port)
//         : io_service_(), acceptor_(io_service_, tcp::endpoint(tcp::v4(), port))
//     {
//         ip_address_ = ip_address;
//         port_ = port;
//         start_accept();
//     }

//     void start_accept()
//     {
//         auto new_connection = std::make_shared<Connection>(io_service_, blockchain_, this);
//         acceptor_.async_accept(new_connection->socket(), boost::bind(&Node::handle_accept, this, new_connection, boost::asio::placeholders::error));
//     }

//     void handle_accept(std::shared_ptr<Connection> connection, const boost::system::error_code& error)
//     {
//         if (!error)
//         {
//             connection->start();
//         }

//         start_accept();
//     }

//     void add_peer(std::string ip_address, unsigned short port)
//     {
//         std::shared_ptr<Peer> peer = std::make_shared<Peer>(ip_address, port);
//         peers_.push_back(peer);
//     }

//     void broadcast(Block block)
//     {
//         for (auto peer : peers_)
//         {
//             peer->send_block(block);
//         }
//     }

//     void receive_block(Block block)
//     {
//         blockchain_.push_back(block);
//         broadcast(block);
//     }

// private:
//     std::string ip_address_;
//     unsigned short port_;
//     std::vector<std::shared_ptr<Peer>> peers_;
//     std::vector<Block> blockchain_;
//     boost::asio::io_service io_service_;
//     tcp::acceptor acceptor_;
// };

// class Connection : public std::enable_shared_from_this<Connection> {
// public:
//     Connection(boost::asio::io_service& io_service, std::vector<Block>& blockchain, Node* node)
//         : socket_(io_service), blockchain_(blockchain), node_(node)
//     {
//     }

//     tcp::socket& socket()
//     {
//         return socket_;
//     }

//     void start()
//     {
//         boost::asio::async_read(socket_, boost::asio::buffer(buffer_), boost::bind(&Connection::handle_read, shared_from_this(), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
//     }

//     void send_block(Block block)
//     {
//         boost::asio::write(socket_, boost::asio::buffer((char*)&block, sizeof(Block)));
//     }

//     void handle_read(const boost::system::error_code& error, size_t bytes_transferred)
//     {
//         if (!error)
//         {
//             Block block = *(Block*)buffer_;
//             blockchain_.push_back(block);
//             node_->broadcast(block);
//         }
//     }

// private:
//     tcp::socket socket_;
//     std::vector<Block>& blockchain_;
//     Node* node_;
//     char buffer_[sizeof(Block)];
// };

// class Peer:
//     def __init__(self, ip_address, port):
//         self.ip_address = ip_address
//         self.port = port
//         self.peer_id = self.generate_peer_id()

//     def generate_peer_id(self):
//         """Generate a 20-byte peer ID for the peer."""
//         return hashlib.sha1(os.urandom(20)).digest()

//     def __str__(self):
//         return f"{self.ip_address}:{self.port}"

//     def __eq__(self, other):
//         """Two peers are considered equal if they have the same IP address and port."""
//         return self.ip_address == other.ip_address and self.port == other.port