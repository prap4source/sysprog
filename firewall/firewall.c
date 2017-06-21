/* Traffic logs come to system with the following specified format 
 * {src_ip, dst_ip, port, timestamp}. Detect a port scan attack.
 * A port scan attack can be defined as
 *
