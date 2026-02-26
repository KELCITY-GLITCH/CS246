#ifndef DSE_TD_H
#define DSE_TD_H

#include <string>
#include "Array.h"

namespace dse{
    class ShortAnswerQuestion {
    public:
     
        enum class Stage {one, two};

        ShortAnswerQuestion(const std::string& question, const std::string& solution, const std::string& result= "");

        virtual ~ShortAnswerQuestion();

        void toggleStage();

        std::string getQuestion() const;
        std::string getAnswer() const;
        std::string getSolution() const;
        Stage getStage() const;

        void setAnswer(const std::string &answer);

        virtual std::string toString() const override;

        private:
            std::string m_question;
            std::string m_solution;
            std::string m_answer;
            Stage m_stage;
     };

        Array<ShortAnswer> makeShortAnswerArray(){
            Array<ShortAnswer>arr (5);
            arr[0] = ShortAnswer("What is a pointer?", "A varuiable that stores the memory address of other variable.");
            arr[1] = ShortAnswer("What is a dynamic memory" ,"A memmory alocated during runtime.");
            arr[2] = ShortAnswer("What is the pointer member aacces operator", "It's used to access member of an object through a pointer.");
            



        };

     







}
#endif
