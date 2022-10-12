using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
public:
  bool canPartition(const vector<int> &num) {
    int sum = 0;
    for (int i = 0; i < num.size(); i++) {
      sum += num[i];
    }
    if (sum % 2 != 0) {
      return false;
    }

    return this->canPartitionRecursive(num, sum / 2, 0);
  }

private:
  bool canPartitionRecursive(const vector<int> &num, int sum, int currentIndex) {
    if (sum == 0) {
      return true;
    }

    if (num.empty() || currentIndex >= num.size()) {
      return false;
    }
    if (num[currentIndex] <= sum) {
      if (canPartitionRecursive(num, sum - num[currentIndex], currentIndex + 1)) {
        return true;
      }
    }
    return canPartitionRecursive(num, sum, currentIndex + 1);
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 4};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 1, 3, 4, 7};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{2, 3, 4, 6};
  cout << ps.canPartition(num) << endl;
}
