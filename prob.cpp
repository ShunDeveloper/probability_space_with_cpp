#include <iostream>
#include <vector>
#include <set>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class SigmaField
{
    public:
        SigmaField(vector<int> sample_space) {
            // confirm sample space is valid
            vector<int> tmp_vector;
            for (int i=0; i< sample_space.size(); i++){
                for (int j=0; j<tmp_vector.size(); j++){
                    if (tmp_vector[j] == sample_space[i]){
                        sample_space_valid = false;
                    }
                }
                tmp_vector.push_back(sample_space[i]);
            }

            // making powerset
            for (int num_of_object=0; num_of_object< sample_space.size(); num_of_object++){
                for (int start_num=0; start_num<sample_space.size(); start_num++){
                    int end_num = start_num + num_of_object;
                    // out of rangeは処理を行わない
                    if (end_num >= sample_space.size()){
                        continue;
                    }
                    // start から end までを追加する
                    vector<int> vec_;
                    for (int i=start_num; i<=end_num; i++){
                        vec_.push_back(sample_space[i]);
                    }
                    power_set.push_back(vec_);
                }
            }
            
            // output the result generating class
            if (sample_space_valid){
                std::cout << "SigmaField is successflly generated" << std::endl;
            } else {
                throw std::invalid_argument("Error: sample space is not have duplicated object");
            }
        };
        bool ShowSampleSpaceValid(){return sample_space_valid;}
        void ShowPowerset(){
            for (int i=0; i < power_set.size(); i++){
                // copy vector as string
                std::ostringstream oss;
                if (!power_set[i].empty()) {
                    std::copy(
                        power_set[i].begin(),
                        power_set[i].end() - 1,
                        std::ostream_iterator<int>(oss, ", ")
                    );
                    oss << power_set[i].back();
                }
                // output string variable
                std::cout << oss.str() << std::endl;
            }
        };

    private:
        set<int> sample_space;
        bool sample_space_valid=true;
        vector<vector<int>> power_set;
};

int main()
{
    const vector<int> omega = {1,2,3,4,5,6}; // sample space
    SigmaField A(omega);
    A.ShowPowerset();
    return 0;
}