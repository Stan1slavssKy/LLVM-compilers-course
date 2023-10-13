; ModuleID = 'game_of_life.cpp'
source_filename = "game_of_life.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@.str = private unnamed_addr constant [11 x i8] c"GameOfLife\00", align 1

; Function Attrs: noinline norecurse optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  call void @grlib_init(i64 1080, i64 720, i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str, i64 0, i64 0), i8 zeroext 0)
  call void @_Z3appv()
  ret i32 0
}

declare dso_local void @grlib_init(i64, i64, i8*, i8 zeroext) #1

; Function Attrs: noinline optnone uwtable
define dso_local void @_Z3appv() #2 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca [777600 x i8], align 16
  %7 = alloca [777600 x i8], align 16
  %8 = alloca i8*, align 8
  %9 = alloca i8*, align 8
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  store i32 -16777216, i32* %1, align 4
  store i32 65280, i32* %2, align 4
  store i32 0, i32* %3, align 4
  %13 = load i32, i32* %2, align 4
  %14 = load i32, i32* %1, align 4
  %15 = add i32 %13, %14
  store i32 %15, i32* %4, align 4
  %16 = load i32, i32* %3, align 4
  %17 = load i32, i32* %1, align 4
  %18 = add i32 %16, %17
  store i32 %18, i32* %5, align 4
  %19 = bitcast [777600 x i8]* %6 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %19, i8 0, i64 777600, i1 false)
  %20 = bitcast [777600 x i8]* %7 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %20, i8 0, i64 777600, i1 false)
  %21 = getelementptr inbounds [777600 x i8], [777600 x i8]* %6, i64 0, i64 0
  store i8* %21, i8** %8, align 8
  %22 = getelementptr inbounds [777600 x i8], [777600 x i8]* %7, i64 0, i64 0
  store i8* %22, i8** %9, align 8
  %23 = load i8*, i8** %8, align 8
  %24 = load i32, i32* %4, align 4
  call void @grlib_set_random_pixels(i64 1080, i64 720, i8* %23, i32 %24)
  br label %25

25:                                               ; preds = %120, %0
  %26 = call i32 @grlib_check_events()
  %27 = icmp ne i32 %26, 0
  %28 = xor i1 %27, true
  br i1 %28, label %29, label %121

29:                                               ; preds = %25
  store i32 0, i32* %10, align 4
  br label %30

30:                                               ; preds = %117, %29
  %31 = load i32, i32* %10, align 4
  %32 = icmp slt i32 %31, 720
  br i1 %32, label %33, label %120

33:                                               ; preds = %30
  store i32 0, i32* %11, align 4
  br label %34

34:                                               ; preds = %113, %33
  %35 = load i32, i32* %11, align 4
  %36 = icmp slt i32 %35, 1080
  br i1 %36, label %37, label %116

37:                                               ; preds = %34
  %38 = load i8*, i8** %8, align 8
  %39 = load i32, i32* %11, align 4
  %40 = load i32, i32* %10, align 4
  %41 = call i32 @_Z23calculate_neighbors_sumPhii(i8* %38, i32 %39, i32 %40)
  store i32 %41, i32* %12, align 4
  %42 = load i32, i32* %12, align 4
  %43 = icmp eq i32 %42, 3
  br i1 %43, label %44, label %58

44:                                               ; preds = %37
  %45 = load i8*, i8** %9, align 8
  %46 = load i32, i32* %10, align 4
  %47 = mul nsw i32 1080, %46
  %48 = sext i32 %47 to i64
  %49 = getelementptr inbounds i8, i8* %45, i64 %48
  %50 = load i32, i32* %11, align 4
  %51 = sext i32 %50 to i64
  %52 = getelementptr inbounds i8, i8* %49, i64 %51
  store i8 1, i8* %52, align 1
  %53 = load i32, i32* %11, align 4
  %54 = sext i32 %53 to i64
  %55 = load i32, i32* %10, align 4
  %56 = sext i32 %55 to i64
  %57 = load i32, i32* %4, align 4
  call void @grlib_set_pixel(i64 %54, i64 %56, i32 %57)
  br label %112

58:                                               ; preds = %37
  %59 = load i32, i32* %12, align 4
  %60 = icmp slt i32 %59, 2
  br i1 %60, label %61, label %75

61:                                               ; preds = %58
  %62 = load i8*, i8** %9, align 8
  %63 = load i32, i32* %10, align 4
  %64 = mul nsw i32 1080, %63
  %65 = sext i32 %64 to i64
  %66 = getelementptr inbounds i8, i8* %62, i64 %65
  %67 = load i32, i32* %11, align 4
  %68 = sext i32 %67 to i64
  %69 = getelementptr inbounds i8, i8* %66, i64 %68
  store i8 0, i8* %69, align 1
  %70 = load i32, i32* %11, align 4
  %71 = sext i32 %70 to i64
  %72 = load i32, i32* %10, align 4
  %73 = sext i32 %72 to i64
  %74 = load i32, i32* %5, align 4
  call void @grlib_set_pixel(i64 %71, i64 %73, i32 %74)
  br label %111

75:                                               ; preds = %58
  %76 = load i32, i32* %12, align 4
  %77 = icmp sgt i32 %76, 3
  br i1 %77, label %78, label %92

78:                                               ; preds = %75
  %79 = load i8*, i8** %9, align 8
  %80 = load i32, i32* %10, align 4
  %81 = mul nsw i32 1080, %80
  %82 = sext i32 %81 to i64
  %83 = getelementptr inbounds i8, i8* %79, i64 %82
  %84 = load i32, i32* %11, align 4
  %85 = sext i32 %84 to i64
  %86 = getelementptr inbounds i8, i8* %83, i64 %85
  store i8 0, i8* %86, align 1
  %87 = load i32, i32* %11, align 4
  %88 = sext i32 %87 to i64
  %89 = load i32, i32* %10, align 4
  %90 = sext i32 %89 to i64
  %91 = load i32, i32* %5, align 4
  call void @grlib_set_pixel(i64 %88, i64 %90, i32 %91)
  br label %110

92:                                               ; preds = %75
  %93 = load i8*, i8** %8, align 8
  %94 = load i32, i32* %10, align 4
  %95 = mul nsw i32 1080, %94
  %96 = sext i32 %95 to i64
  %97 = getelementptr inbounds i8, i8* %93, i64 %96
  %98 = load i32, i32* %11, align 4
  %99 = sext i32 %98 to i64
  %100 = getelementptr inbounds i8, i8* %97, i64 %99
  %101 = load i8, i8* %100, align 1
  %102 = load i8*, i8** %9, align 8
  %103 = load i32, i32* %10, align 4
  %104 = mul nsw i32 1080, %103
  %105 = sext i32 %104 to i64
  %106 = getelementptr inbounds i8, i8* %102, i64 %105
  %107 = load i32, i32* %11, align 4
  %108 = sext i32 %107 to i64
  %109 = getelementptr inbounds i8, i8* %106, i64 %108
  store i8 %101, i8* %109, align 1
  br label %110

110:                                              ; preds = %92, %78
  br label %111

111:                                              ; preds = %110, %61
  br label %112

112:                                              ; preds = %111, %44
  br label %113

113:                                              ; preds = %112
  %114 = load i32, i32* %11, align 4
  %115 = add nsw i32 %114, 1
  store i32 %115, i32* %11, align 4
  br label %34

116:                                              ; preds = %34
  br label %117

117:                                              ; preds = %116
  %118 = load i32, i32* %10, align 4
  %119 = add nsw i32 %118, 1
  store i32 %119, i32* %10, align 4
  br label %30

120:                                              ; preds = %30
  call void @grlib_update_window()
  call void @_Z4swapPPhS0_(i8** %8, i8** %9)
  br label %25

121:                                              ; preds = %25
  ret void
}

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #3

declare dso_local void @grlib_set_random_pixels(i64, i64, i8*, i32) #1

declare dso_local i32 @grlib_check_events() #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @_Z23calculate_neighbors_sumPhii(i8* %0, i32 %1, i32 %2) #4 {
  %4 = alloca i8*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  store i8* %0, i8** %4, align 8
  store i32 %1, i32* %5, align 4
  store i32 %2, i32* %6, align 4
  store i32 0, i32* %7, align 4
  store i32 -1, i32* %8, align 4
  br label %10

10:                                               ; preds = %42, %3
  %11 = load i32, i32* %8, align 4
  %12 = icmp sle i32 %11, 1
  br i1 %12, label %13, label %45

13:                                               ; preds = %10
  store i32 -1, i32* %9, align 4
  br label %14

14:                                               ; preds = %38, %13
  %15 = load i32, i32* %9, align 4
  %16 = icmp sle i32 %15, 1
  br i1 %16, label %17, label %41

17:                                               ; preds = %14
  %18 = load i8*, i8** %4, align 8
  %19 = load i32, i32* %6, align 4
  %20 = load i32, i32* %9, align 4
  %21 = add nsw i32 %19, %20
  %22 = add nsw i32 %21, 720
  %23 = srem i32 %22, 720
  %24 = mul nsw i32 1080, %23
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds i8, i8* %18, i64 %25
  %27 = load i32, i32* %5, align 4
  %28 = load i32, i32* %8, align 4
  %29 = add nsw i32 %27, %28
  %30 = add nsw i32 %29, 1080
  %31 = srem i32 %30, 1080
  %32 = sext i32 %31 to i64
  %33 = getelementptr inbounds i8, i8* %26, i64 %32
  %34 = load i8, i8* %33, align 1
  %35 = zext i8 %34 to i32
  %36 = load i32, i32* %7, align 4
  %37 = add nsw i32 %36, %35
  store i32 %37, i32* %7, align 4
  br label %38

38:                                               ; preds = %17
  %39 = load i32, i32* %9, align 4
  %40 = add nsw i32 %39, 1
  store i32 %40, i32* %9, align 4
  br label %14

41:                                               ; preds = %14
  br label %42

42:                                               ; preds = %41
  %43 = load i32, i32* %8, align 4
  %44 = add nsw i32 %43, 1
  store i32 %44, i32* %8, align 4
  br label %10

45:                                               ; preds = %10
  %46 = load i8*, i8** %4, align 8
  %47 = load i32, i32* %6, align 4
  %48 = mul nsw i32 1080, %47
  %49 = sext i32 %48 to i64
  %50 = getelementptr inbounds i8, i8* %46, i64 %49
  %51 = load i32, i32* %5, align 4
  %52 = sext i32 %51 to i64
  %53 = getelementptr inbounds i8, i8* %50, i64 %52
  %54 = load i8, i8* %53, align 1
  %55 = zext i8 %54 to i32
  %56 = load i32, i32* %7, align 4
  %57 = sub nsw i32 %56, %55
  store i32 %57, i32* %7, align 4
  %58 = load i32, i32* %7, align 4
  ret i32 %58
}

declare dso_local void @grlib_set_pixel(i64, i64, i32) #1

declare dso_local void @grlib_update_window() #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_Z4swapPPhS0_(i8** %0, i8** %1) #4 {
  %3 = alloca i8**, align 8
  %4 = alloca i8**, align 8
  %5 = alloca i8*, align 8
  store i8** %0, i8*** %3, align 8
  store i8** %1, i8*** %4, align 8
  %6 = load i8**, i8*** %3, align 8
  %7 = load i8*, i8** %6, align 8
  store i8* %7, i8** %5, align 8
  %8 = load i8**, i8*** %4, align 8
  %9 = load i8*, i8** %8, align 8
  %10 = load i8**, i8*** %3, align 8
  store i8* %9, i8** %10, align 8
  %11 = load i8*, i8** %5, align 8
  %12 = load i8**, i8*** %4, align 8
  store i8* %11, i8** %12, align 8
  ret void
}

attributes #0 = { noinline norecurse optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noinline optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { argmemonly nounwind willreturn }
attributes #4 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
