#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

namespace llvm {
namespace {
    struct MyPass : public FunctionPass {
    static char ID;
    MyPass() : FunctionPass(ID) {}

    inline bool isFuncLogger(StringRef name)
    {
        return name == "log_instruction";
    }

    virtual bool runOnFunction(Function &F) {
        if (isFuncLogger(F.getName())) {
            return false;
        }

        LLVMContext &Ctx = F.getContext();
        IRBuilder<> builder(Ctx);
        Type *retType = Type::getVoidTy(Ctx);

        ArrayRef<Type *> logInstructionParamTypes = { builder.getInt8Ty()->getPointerTo() };
        FunctionType *logInstructionFuncType = FunctionType::get(retType, logInstructionParamTypes, false);
        FunctionCallee logInstructionFunc = F.getParent()->getOrInsertFunction("log_instruction", logInstructionFuncType);

        for (auto &B : F) {
            for (auto &I : B) {
                if (auto *phi = dyn_cast<PHINode>(&I)) {
                    continue;
                }
                builder.SetInsertPoint(&I);

                Value *opName = builder.CreateGlobalStringPtr(I.getOpcodeName());
                if (opName) {
                    Value *args[] = {opName};
                    builder.CreateCall(logInstructionFunc, args);  
                }        
            }
        }

        return true;
    }
};

} // namespace

char MyPass::ID = 0;

static void registerMyPass(const PassManagerBuilder &, legacy::PassManagerBase &PM) {
    PM.add(new MyPass());
}

static RegisterStandardPasses RegisterMyPass(PassManagerBuilder::EP_OptimizerLast, registerMyPass);

} // namespace llvm
