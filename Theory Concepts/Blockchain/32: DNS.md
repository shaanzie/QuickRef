# DNS

- Domain Name System is mainly used to resolve a hostname query to an IP address

- DNS services provide
  - Anti-spam
    - Sender Policy Framework (SPF) and Domain Keys Identified Mail (DKIM) ensure only a predefined list of domains allowed to send emails
  - Load sharing
  - Privacy

- Namespace is a structure of the DNS database. It consists of the root node, top level node and second level and third level nodes.

- Name servers are used to store information of zones
  - Can be authoritative or caching services
  - Authoritative name servers provide responses to DNS queries
  - The master/primary name server stores original copies of all zone records
  - The slave keeps a copy of the master files
  - The caching server brings the name server closer to the user and improves lookup performance

- A resolver is required to find out the name and IP address of name servers for the root zone
  - Root server stores all TLDs

- DNS records are mapping files that associate DNS servers to IP addresses
  - MX - Mail exchanges
  - TXT - Expand DNS information (SPF)
  - CNAME - domain and subdomain text aliases, indicate Secure File Transfer Protocol (SFTP)
  - PTR - Reverse bindings from addresses to names

- DNS spoofing
  - DNS cache poisoning - Forged DNS entries into the DNS servers
  - Compromising DNS servers
  - Man in the middle attack - listen to client requests to the DNS

- DNSChain is a blockchain based DNS solution
  - Delivers MITM proofs of authentication, replacing PKI
  - Uses public key pinning to get rid of MITMs