#ifndef MODEL_HPP
#define MODEL_HPP

#define COUNT_MAX 11
class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void turnLedOn(int idx);
    int* setUpGame(int count);
    int saveAnswer(int idx);
    bool isCorrect();
    bool getCorrect();
    void destroyGame();

protected:
    ModelListener* modelListener;

private:
    //state variables
    int problem[COUNT_MAX];
    int problemCnt;
    int userAnswer[COUNT_MAX];
    int userAnswerCnt;
    bool isSolved;
    const int countMax = COUNT_MAX;
};

#endif // MODEL_HPP
