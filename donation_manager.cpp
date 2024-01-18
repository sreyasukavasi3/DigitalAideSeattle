#include <iostream>
#include <vector>
#include <unordered_map>

struct Donation {
    std::string donorName;
    std::string donationType;
    double amount;
    std::string date;
};

class DonationManager {
private:
    std::vector<Donation> donations;
    std::unordered_map<std::string, double> totalDonationsByDonor;

public:
    void registerDonation(const Donation& donation) {
        donations.push_back(donation);
        totalDonationsByDonor[donation.donorName] += donation.amount;
        std::cout << "Donation registered successfully.\n";
    }

    void distributeDonation(const std::string& donorName, double amount, const std::string& date) {
        auto it = totalDonationsByDonor.find(donorName);
        if (it != totalDonationsByDonor.end() && it->second >= amount) {
            it->second -= amount;
            std::cout << "Donation distributed successfully.\n";
        } else {
            std::cout << "Insufficient donation amount for distribution.\n";
        }
    }

    void generateInventoryReport() const {
        std::cout << "Inventory Report:\n";
        for (const auto& donation : donations) {
            std::cout << "Donation Type: " << donation.donationType << ", Quantity/Amount: " << donation.amount << "\n";
        }
    }

    void generateDonorReport() const {
        std::cout << "Donor Report:\n";
        for (const auto& entry : totalDonationsByDonor) {
            std::cout << "Donor: " << entry.first << ", Total Contribution: " << entry.second << "\n";
        }
    }
};

int main() {
    DonationManager donationManager;

    Donation donation1{"John Doe", "Money", 100.0, "2022-01-01"};
    Donation donation2{"Jane Smith", "Food", 50.0, "2022-02-15"};

    donationManager.registerDonation(donation1);
    donationManager.registerDonation(donation2);

    donationManager.distributeDonation("John Doe", 80.0, "2022-03-01");

    donationManager.generateInventoryReport();
    donationManager.generateDonorReport();

    return 0;
}
