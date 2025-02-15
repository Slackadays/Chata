import os

def write_to_sh_file(ip, username, path):
    with open("credentials.sh", "w") as file:
        file.write(f"export CHATA_CROSS_IP={ip}\n")
        file.write(f"export CHATA_CROSS_USERNAME={username}\n")
        file.write(f"export CHATA_CROSS_PATH={path}\n")

def main():
    if os.path.exists("credentials.sh"):
        print("Credentials present")
        return

    ip = input("Enter IP: ")
    username = input("Enter Username: ")
    path = input("Enter Path: ")
    
    write_to_sh_file(ip, username, path)
    print("Credentials saved to credentials.sh")

if __name__ == "__main__":
    main()