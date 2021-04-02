; ModuleID = 'converter'
source_filename = "converter"

@RegFile = private global [32 x i32] zeroinitializer, align 8

define void @Func(i8* %pBuff) {
BB:
  %0 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %1 = add i32 %0, -32
  store i32 %1, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %2 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %3 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %4 = bitcast i8* %pBuff to i32*
  %5 = add i32 %2, 28
  %6 = getelementptr i32, i32* %4, i32 %5
  store i32 %3, i32* %6, align 4
  %7 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %8 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %9 = bitcast i8* %pBuff to i32*
  %10 = add i32 %7, 24
  %11 = getelementptr i32, i32* %9, i32 %10
  store i32 %8, i32* %11, align 4
  %12 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %13 = add i32 %12, 32
  store i32 %13, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  call void @Func.1(i8* %pBuff)
  store i32 66528, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %14 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %15 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %16 = bitcast i8* %pBuff to i32*
  %17 = add i32 %14, -20
  %18 = getelementptr i32, i32* %16, i32 %17
  store i32 %15, i32* %18, align 4
  %19 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %20 = add i32 %19, -20
  %21 = bitcast i8* %pBuff to i32*
  %22 = getelementptr i32, i32* %21, i32 %20
  %23 = load i32, i32* %22, align 4
  store i32 %23, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  call void @Func.2(i8* %pBuff)
  store i32 66540, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  ret void
}

define void @Func.1(i8* %pBuff) {
BB:
  %0 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %1 = add i32 %0, -464
  store i32 %1, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %2 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %3 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %4 = bitcast i8* %pBuff to i32*
  %5 = add i32 %2, 460
  %6 = getelementptr i32, i32* %4, i32 %5
  store i32 %3, i32* %6, align 4
  %7 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %8 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %9 = bitcast i8* %pBuff to i32*
  %10 = add i32 %7, 456
  %11 = getelementptr i32, i32* %9, i32 %10
  store i32 %8, i32* %11, align 4
  %12 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %13 = add i32 %12, 464
  store i32 %13, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  store i32 405504, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %14 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %15 = add i32 %14, 1312
  store i32 %15, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %16 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %17 = add i32 %16, 0
  %18 = bitcast i8* %pBuff to i32*
  %19 = getelementptr i32, i32* %18, i32 %17
  %20 = load i32, i32* %19, align 4
  store i32 %20, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 17), align 4
  %21 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %22 = add i32 %21, 4
  %23 = bitcast i8* %pBuff to i32*
  %24 = getelementptr i32, i32* %23, i32 %22
  %25 = load i32, i32* %24, align 4
  store i32 %25, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 16), align 4
  %26 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %27 = add i32 %26, 8
  %28 = bitcast i8* %pBuff to i32*
  %29 = getelementptr i32, i32* %28, i32 %27
  %30 = load i32, i32* %29, align 4
  store i32 %30, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %31 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %32 = add i32 %31, 12
  %33 = bitcast i8* %pBuff to i32*
  %34 = getelementptr i32, i32* %33, i32 %32
  %35 = load i32, i32* %34, align 4
  store i32 %35, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %36 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %37 = add i32 %36, 16
  %38 = bitcast i8* %pBuff to i32*
  %39 = getelementptr i32, i32* %38, i32 %37
  %40 = load i32, i32* %39, align 4
  store i32 %40, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 12), align 4
  %41 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %42 = add i32 %41, 20
  %43 = bitcast i8* %pBuff to i32*
  %44 = getelementptr i32, i32* %43, i32 %42
  %45 = load i32, i32* %44, align 4
  store i32 %45, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 13), align 4
  %46 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %47 = add i32 %46, 24
  %48 = bitcast i8* %pBuff to i32*
  %49 = getelementptr i32, i32* %48, i32 %47
  %50 = load i32, i32* %49, align 4
  store i32 %50, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %51 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %52 = add i32 %51, 28
  %53 = bitcast i8* %pBuff to i32*
  %54 = getelementptr i32, i32* %53, i32 %52
  %55 = load i32, i32* %54, align 4
  store i32 %55, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %56 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %57 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 17), align 4
  %58 = bitcast i8* %pBuff to i32*
  %59 = add i32 %56, -452
  %60 = getelementptr i32, i32* %58, i32 %59
  store i32 %57, i32* %60, align 4
  %61 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %62 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 16), align 4
  %63 = bitcast i8* %pBuff to i32*
  %64 = add i32 %61, -448
  %65 = getelementptr i32, i32* %63, i32 %64
  store i32 %62, i32* %65, align 4
  %66 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %67 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %68 = bitcast i8* %pBuff to i32*
  %69 = add i32 %66, -444
  %70 = getelementptr i32, i32* %68, i32 %69
  store i32 %67, i32* %70, align 4
  %71 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %72 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %73 = bitcast i8* %pBuff to i32*
  %74 = add i32 %71, -440
  %75 = getelementptr i32, i32* %73, i32 %74
  store i32 %72, i32* %75, align 4
  %76 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %77 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 12), align 4
  %78 = bitcast i8* %pBuff to i32*
  %79 = add i32 %76, -436
  %80 = getelementptr i32, i32* %78, i32 %79
  store i32 %77, i32* %80, align 4
  %81 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %82 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 13), align 4
  %83 = bitcast i8* %pBuff to i32*
  %84 = add i32 %81, -432
  %85 = getelementptr i32, i32* %83, i32 %84
  store i32 %82, i32* %85, align 4
  %86 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %87 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %88 = bitcast i8* %pBuff to i32*
  %89 = add i32 %86, -428
  %90 = getelementptr i32, i32* %88, i32 %89
  store i32 %87, i32* %90, align 4
  %91 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %92 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %93 = bitcast i8* %pBuff to i32*
  %94 = add i32 %91, -424
  %95 = getelementptr i32, i32* %93, i32 %94
  store i32 %92, i32* %95, align 4
  %96 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %97 = add i32 %96, 1
  store i32 %97, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %98 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %99 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %100 = bitcast i8* %pBuff to i32*
  %101 = add i32 %98, -20
  %102 = getelementptr i32, i32* %100, i32 %101
  store i32 %99, i32* %102, align 4
  br label %BB4

BB1:                                              ; preds = %BB4
  %103 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 3), align 4
  %104 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %105 = bitcast i8* %pBuff to i32*
  %106 = add i32 %103, -1048
  %107 = getelementptr i32, i32* %105, i32 %106
  store i32 %104, i32* %107, align 4
  %108 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %109 = add i32 %108, -20
  %110 = bitcast i8* %pBuff to i32*
  %111 = getelementptr i32, i32* %110, i32 %109
  %112 = load i32, i32* %111, align 4
  store i32 %112, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %113 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %114 = add i32 %113, -420
  store i32 %114, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %115 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %116 = add i32 %115, 0
  store i32 %116, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 12), align 4
  %117 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %118 = add i32 %117, 0
  store i32 %118, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %119 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %120 = add i32 %119, 0
  store i32 %120, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  call void @Func.6(i8* %pBuff)
  store i32 67376, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %121 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %122 = add i32 %121, -20
  %123 = bitcast i8* %pBuff to i32*
  %124 = getelementptr i32, i32* %123, i32 %122
  %125 = load i32, i32* %124, align 4
  store i32 %125, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %126 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %127 = add i32 %126, -1
  store i32 %127, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %128 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %129 = shl i32 %128, 2
  store i32 %129, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %130 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %131 = add i32 %130, -16
  store i32 %131, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %132 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %133 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %134 = add i32 %132, %133
  store i32 %134, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %135 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %136 = add i32 %135, -436
  %137 = bitcast i8* %pBuff to i32*
  %138 = getelementptr i32, i32* %137, i32 %136
  %139 = load i32, i32* %138, align 4
  store i32 %139, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %140 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 3), align 4
  %141 = add i32 %140, -1048
  %142 = bitcast i8* %pBuff to i32*
  %143 = getelementptr i32, i32* %142, i32 %141
  %144 = load i32, i32* %143, align 4
  store i32 %144, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %145 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %146 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %147 = icmp eq i32 %145, %146
  br i1 %147, label %BB3, label %BB2

BB2:                                              ; preds = %BB1
  call void @Func.8(i8* %pBuff)
  store i32 67412, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  br label %BB3

BB3:                                              ; preds = %BB2, %BB1
  %148 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %149 = add i32 %148, -20
  %150 = bitcast i8* %pBuff to i32*
  %151 = getelementptr i32, i32* %150, i32 %149
  %152 = load i32, i32* %151, align 4
  store i32 %152, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %153 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %154 = add i32 %153, 1
  store i32 %154, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %155 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %156 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %157 = bitcast i8* %pBuff to i32*
  %158 = add i32 %155, -20
  %159 = getelementptr i32, i32* %157, i32 %158
  store i32 %156, i32* %159, align 4
  br label %BB4

BB4:                                              ; preds = %BB3, %BB
  %160 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %161 = add i32 %160, -20
  %162 = bitcast i8* %pBuff to i32*
  %163 = getelementptr i32, i32* %162, i32 %161
  %164 = load i32, i32* %163, align 4
  store i32 %164, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %165 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %166 = add i32 %165, 8
  store i32 %166, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %167 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %168 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %169 = icmp sge i32 %167, %168
  br i1 %169, label %BB1, label %BB5

BB5:                                              ; preds = %BB4
  %170 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %171 = add i32 %170, 0
  store i32 %171, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %172 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %173 = add i32 %172, 0
  store i32 %173, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %174 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %175 = add i32 %174, 460
  %176 = bitcast i8* %pBuff to i32*
  %177 = getelementptr i32, i32* %176, i32 %175
  %178 = load i32, i32* %177, align 4
  store i32 %178, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %179 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %180 = add i32 %179, 456
  %181 = bitcast i8* %pBuff to i32*
  %182 = getelementptr i32, i32* %181, i32 %180
  %183 = load i32, i32* %182, align 4
  store i32 %183, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %184 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %185 = add i32 %184, 464
  store i32 %185, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %186 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  ret void
}

define void @Func.2(i8* %pBuff) {
BB:
  ret void
}

define void @Func.3(i8* %pBuff) {
BB:
  %0 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %1 = add i32 %0, -32
  store i32 %1, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %2 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %3 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %4 = bitcast i8* %pBuff to i32*
  %5 = add i32 %2, 28
  %6 = getelementptr i32, i32* %4, i32 %5
  store i32 %3, i32* %6, align 4
  %7 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %8 = add i32 %7, 32
  store i32 %8, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %9 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %10 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %11 = bitcast i8* %pBuff to i32*
  %12 = add i32 %9, -20
  %13 = getelementptr i32, i32* %11, i32 %12
  store i32 %10, i32* %13, align 4
  %14 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %15 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %16 = bitcast i8* %pBuff to i32*
  %17 = add i32 %14, -24
  %18 = getelementptr i32, i32* %16, i32 %17
  store i32 %15, i32* %18, align 4
  %19 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %20 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 12), align 4
  %21 = bitcast i8* %pBuff to i32*
  %22 = add i32 %19, -28
  %23 = getelementptr i32, i32* %21, i32 %22
  store i32 %20, i32* %23, align 4
  %24 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %25 = add i32 %24, -24
  %26 = bitcast i8* %pBuff to i32*
  %27 = getelementptr i32, i32* %26, i32 %25
  %28 = load i32, i32* %27, align 4
  store i32 %28, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %29 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %30 = add i32 %29, -28
  %31 = bitcast i8* %pBuff to i32*
  %32 = getelementptr i32, i32* %31, i32 %30
  %33 = load i32, i32* %32, align 4
  store i32 %33, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %34 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %35 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %36 = sub i32 %34, %35
  store i32 %36, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %37 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %38 = icmp ult i32 %37, 1
  %39 = zext i1 %38 to i32
  store i32 %39, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %40 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %41 = and i32 %40, 255
  store i32 %41, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %42 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %43 = add i32 %42, 0
  store i32 %43, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %44 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %45 = add i32 %44, 28
  %46 = bitcast i8* %pBuff to i32*
  %47 = getelementptr i32, i32* %46, i32 %45
  %48 = load i32, i32* %47, align 4
  store i32 %48, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %49 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %50 = add i32 %49, 32
  store i32 %50, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %51 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  ret void
}

define void @Func.4(i8* %pBuff) {
BB:
  %0 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %1 = add i32 %0, -32
  store i32 %1, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %2 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %3 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %4 = bitcast i8* %pBuff to i32*
  %5 = add i32 %2, 28
  %6 = getelementptr i32, i32* %4, i32 %5
  store i32 %3, i32* %6, align 4
  %7 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %8 = add i32 %7, 32
  store i32 %8, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %9 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %10 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %11 = bitcast i8* %pBuff to i32*
  %12 = add i32 %9, -20
  %13 = getelementptr i32, i32* %11, i32 %12
  store i32 %10, i32* %13, align 4
  %14 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %15 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %16 = bitcast i8* %pBuff to i32*
  %17 = add i32 %14, -24
  %18 = getelementptr i32, i32* %16, i32 %17
  store i32 %15, i32* %18, align 4
  %19 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 3), align 4
  %20 = add i32 %19, -1048
  %21 = bitcast i8* %pBuff to i32*
  %22 = getelementptr i32, i32* %21, i32 %20
  %23 = load i32, i32* %22, align 4
  store i32 %23, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %24 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %25 = add i32 %24, 1
  store i32 %25, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %26 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 3), align 4
  %27 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %28 = bitcast i8* %pBuff to i32*
  %29 = add i32 %26, -1048
  %30 = getelementptr i32, i32* %28, i32 %29
  store i32 %27, i32* %30, align 4
  %31 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %32 = add i32 %31, 0
  %33 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %34 = add i32 %33, 0
  store i32 %34, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %35 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %36 = add i32 %35, 28
  %37 = bitcast i8* %pBuff to i32*
  %38 = getelementptr i32, i32* %37, i32 %36
  %39 = load i32, i32* %38, align 4
  store i32 %39, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %40 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %41 = add i32 %40, 32
  store i32 %41, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %42 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  ret void
}

define void @Func.5(i8* %pBuff) {
BB:
  %0 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %1 = add i32 %0, -64
  store i32 %1, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %2 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %3 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %4 = bitcast i8* %pBuff to i32*
  %5 = add i32 %2, 60
  %6 = getelementptr i32, i32* %4, i32 %5
  store i32 %3, i32* %6, align 4
  %7 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %8 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %9 = bitcast i8* %pBuff to i32*
  %10 = add i32 %7, 56
  %11 = getelementptr i32, i32* %9, i32 %10
  store i32 %8, i32* %11, align 4
  %12 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %13 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 9), align 4
  %14 = bitcast i8* %pBuff to i32*
  %15 = add i32 %12, 52
  %16 = getelementptr i32, i32* %14, i32 %15
  store i32 %13, i32* %16, align 4
  %17 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %18 = add i32 %17, 64
  store i32 %18, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %19 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %20 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %21 = bitcast i8* %pBuff to i32*
  %22 = add i32 %19, -36
  %23 = getelementptr i32, i32* %21, i32 %22
  store i32 %20, i32* %23, align 4
  %24 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %25 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %26 = bitcast i8* %pBuff to i32*
  %27 = add i32 %24, -40
  %28 = getelementptr i32, i32* %26, i32 %27
  store i32 %25, i32* %28, align 4
  %29 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %30 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 12), align 4
  %31 = bitcast i8* %pBuff to i32*
  %32 = add i32 %29, -44
  %33 = getelementptr i32, i32* %31, i32 %32
  store i32 %30, i32* %33, align 4
  %34 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %35 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 13), align 4
  %36 = bitcast i8* %pBuff to i32*
  %37 = add i32 %34, -48
  %38 = getelementptr i32, i32* %36, i32 %37
  store i32 %35, i32* %38, align 4
  %39 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %40 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %41 = bitcast i8* %pBuff to i32*
  %42 = add i32 %39, -52
  %43 = getelementptr i32, i32* %41, i32 %42
  store i32 %40, i32* %43, align 4
  %44 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %45 = add i32 %44, -52
  %46 = bitcast i8* %pBuff to i32*
  %47 = getelementptr i32, i32* %46, i32 %45
  %48 = load i32, i32* %47, align 4
  store i32 %48, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %49 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %50 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %51 = bitcast i8* %pBuff to i32*
  %52 = add i32 %49, 0
  %53 = getelementptr i32, i32* %51, i32 %52
  store i32 %50, i32* %53, align 4
  %54 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %55 = add i32 %54, 1
  store i32 %55, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %56 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %57 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %58 = bitcast i8* %pBuff to i32*
  %59 = add i32 %56, -20
  %60 = getelementptr i32, i32* %58, i32 %59
  store i32 %57, i32* %60, align 4
  br label %BB11

BB1:                                              ; preds = %BB11
  %61 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %62 = add i32 %61, 1
  store i32 %62, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %63 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %64 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %65 = bitcast i8* %pBuff to i32*
  %66 = add i32 %63, -28
  %67 = getelementptr i32, i32* %65, i32 %66
  store i32 %64, i32* %67, align 4
  %68 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %69 = add i32 %68, 1
  store i32 %69, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %70 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %71 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %72 = bitcast i8* %pBuff to i32*
  %73 = add i32 %70, -24
  %74 = getelementptr i32, i32* %72, i32 %73
  store i32 %71, i32* %74, align 4
  br label %BB7

BB2:                                              ; preds = %BB7
  %75 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %76 = add i32 %75, -40
  %77 = bitcast i8* %pBuff to i32*
  %78 = getelementptr i32, i32* %77, i32 %76
  %79 = load i32, i32* %78, align 4
  store i32 %79, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %80 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %81 = add i32 %80, -24
  %82 = bitcast i8* %pBuff to i32*
  %83 = getelementptr i32, i32* %82, i32 %81
  %84 = load i32, i32* %83, align 4
  store i32 %84, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %85 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %86 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %87 = sub i32 %85, %86
  store i32 %87, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %88 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %89 = add i32 %88, 0
  store i32 %89, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  call void @Func.7(i8* %pBuff)
  store i32 67028, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %90 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %91 = add i32 %90, 0
  store i32 %91, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 9), align 4
  %92 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %93 = add i32 %92, -24
  %94 = bitcast i8* %pBuff to i32*
  %95 = getelementptr i32, i32* %94, i32 %93
  %96 = load i32, i32* %95, align 4
  store i32 %96, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %97 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %98 = shl i32 %97, 2
  store i32 %98, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %99 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %100 = add i32 %99, -36
  %101 = bitcast i8* %pBuff to i32*
  %102 = getelementptr i32, i32* %101, i32 %100
  %103 = load i32, i32* %102, align 4
  store i32 %103, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %104 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %105 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %106 = add i32 %104, %105
  store i32 %106, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %107 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %108 = add i32 %107, 0
  %109 = bitcast i8* %pBuff to i32*
  %110 = getelementptr i32, i32* %109, i32 %108
  %111 = load i32, i32* %110, align 4
  store i32 %111, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %112 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %113 = add i32 %112, -20
  %114 = bitcast i8* %pBuff to i32*
  %115 = getelementptr i32, i32* %114, i32 %113
  %116 = load i32, i32* %115, align 4
  store i32 %116, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %117 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %118 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %119 = sub i32 %117, %118
  store i32 %119, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %120 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %121 = add i32 %120, 0
  store i32 %121, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  call void @Func.7(i8* %pBuff)
  store i32 67068, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %122 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %123 = add i32 %122, 0
  store i32 %123, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %124 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 9), align 4
  %125 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %126 = icmp ne i32 %124, %125
  br i1 %126, label %BB4, label %BB3

BB3:                                              ; preds = %BB2
  %127 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %128 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %129 = bitcast i8* %pBuff to i32*
  %130 = add i32 %127, -28
  %131 = getelementptr i32, i32* %129, i32 %130
  store i32 %128, i32* %131, align 4
  br label %BB4

BB4:                                              ; preds = %BB3, %BB2
  %132 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %133 = add i32 %132, -24
  %134 = bitcast i8* %pBuff to i32*
  %135 = getelementptr i32, i32* %134, i32 %133
  %136 = load i32, i32* %135, align 4
  store i32 %136, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %137 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %138 = shl i32 %137, 2
  store i32 %138, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %139 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %140 = add i32 %139, -36
  %141 = bitcast i8* %pBuff to i32*
  %142 = getelementptr i32, i32* %141, i32 %140
  %143 = load i32, i32* %142, align 4
  store i32 %143, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %144 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %145 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %146 = add i32 %144, %145
  store i32 %146, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %147 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %148 = add i32 %147, 0
  %149 = bitcast i8* %pBuff to i32*
  %150 = getelementptr i32, i32* %149, i32 %148
  %151 = load i32, i32* %150, align 4
  store i32 %151, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %152 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %153 = add i32 %152, -20
  %154 = bitcast i8* %pBuff to i32*
  %155 = getelementptr i32, i32* %154, i32 %153
  %156 = load i32, i32* %155, align 4
  store i32 %156, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %157 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %158 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %159 = icmp ne i32 %157, %158
  br i1 %159, label %BB6, label %BB5

BB5:                                              ; preds = %BB4
  %160 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %161 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %162 = bitcast i8* %pBuff to i32*
  %163 = add i32 %160, -28
  %164 = getelementptr i32, i32* %162, i32 %163
  store i32 %161, i32* %164, align 4
  br label %BB6

BB6:                                              ; preds = %BB5, %BB4
  %165 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %166 = add i32 %165, -24
  %167 = bitcast i8* %pBuff to i32*
  %168 = getelementptr i32, i32* %167, i32 %166
  %169 = load i32, i32* %168, align 4
  store i32 %169, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %170 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %171 = add i32 %170, 1
  store i32 %171, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %172 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %173 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %174 = bitcast i8* %pBuff to i32*
  %175 = add i32 %172, -24
  %176 = getelementptr i32, i32* %174, i32 %175
  store i32 %173, i32* %176, align 4
  br label %BB7

BB7:                                              ; preds = %BB6, %BB1
  %177 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %178 = add i32 %177, -24
  %179 = bitcast i8* %pBuff to i32*
  %180 = getelementptr i32, i32* %179, i32 %178
  %181 = load i32, i32* %180, align 4
  store i32 %181, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %182 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %183 = add i32 %182, -40
  %184 = bitcast i8* %pBuff to i32*
  %185 = getelementptr i32, i32* %184, i32 %183
  %186 = load i32, i32* %185, align 4
  store i32 %186, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %187 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %188 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %189 = icmp slt i32 %187, %188
  br i1 %189, label %BB2, label %BB8

BB8:                                              ; preds = %BB7
  %190 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %191 = add i32 %190, -28
  %192 = bitcast i8* %pBuff to i32*
  %193 = getelementptr i32, i32* %192, i32 %191
  %194 = load i32, i32* %193, align 4
  store i32 %194, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %195 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %196 = add i32 %195, 1
  store i32 %196, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %197 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %198 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %199 = icmp ne i32 %197, %198
  br i1 %199, label %BB10, label %BB9

BB9:                                              ; preds = %BB8
  %200 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %201 = add i32 %200, -52
  %202 = bitcast i8* %pBuff to i32*
  %203 = getelementptr i32, i32* %202, i32 %201
  %204 = load i32, i32* %203, align 4
  store i32 %204, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %205 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %206 = add i32 %205, 0
  %207 = bitcast i8* %pBuff to i32*
  %208 = getelementptr i32, i32* %207, i32 %206
  %209 = load i32, i32* %208, align 4
  store i32 %209, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %210 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %211 = shl i32 %210, 2
  store i32 %211, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %212 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %213 = add i32 %212, -48
  %214 = bitcast i8* %pBuff to i32*
  %215 = getelementptr i32, i32* %214, i32 %213
  %216 = load i32, i32* %215, align 4
  store i32 %216, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %217 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %218 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %219 = add i32 %217, %218
  store i32 %219, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %220 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %221 = add i32 %220, -20
  %222 = bitcast i8* %pBuff to i32*
  %223 = getelementptr i32, i32* %222, i32 %221
  %224 = load i32, i32* %223, align 4
  store i32 %224, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %225 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %226 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %227 = bitcast i8* %pBuff to i32*
  %228 = add i32 %225, 0
  %229 = getelementptr i32, i32* %227, i32 %228
  store i32 %226, i32* %229, align 4
  %230 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %231 = add i32 %230, -52
  %232 = bitcast i8* %pBuff to i32*
  %233 = getelementptr i32, i32* %232, i32 %231
  %234 = load i32, i32* %233, align 4
  store i32 %234, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %235 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %236 = add i32 %235, 0
  %237 = bitcast i8* %pBuff to i32*
  %238 = getelementptr i32, i32* %237, i32 %236
  %239 = load i32, i32* %238, align 4
  store i32 %239, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %240 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %241 = add i32 %240, 1
  store i32 %241, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %242 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %243 = add i32 %242, -52
  %244 = bitcast i8* %pBuff to i32*
  %245 = getelementptr i32, i32* %244, i32 %243
  %246 = load i32, i32* %245, align 4
  store i32 %246, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %247 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %248 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %249 = bitcast i8* %pBuff to i32*
  %250 = add i32 %247, 0
  %251 = getelementptr i32, i32* %249, i32 %250
  store i32 %248, i32* %251, align 4
  br label %BB10

BB10:                                             ; preds = %BB9, %BB8
  %252 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %253 = add i32 %252, -20
  %254 = bitcast i8* %pBuff to i32*
  %255 = getelementptr i32, i32* %254, i32 %253
  %256 = load i32, i32* %255, align 4
  store i32 %256, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %257 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %258 = add i32 %257, 1
  store i32 %258, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %259 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %260 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %261 = bitcast i8* %pBuff to i32*
  %262 = add i32 %259, -20
  %263 = getelementptr i32, i32* %261, i32 %262
  store i32 %260, i32* %263, align 4
  br label %BB11

BB11:                                             ; preds = %BB10, %BB
  %264 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %265 = add i32 %264, -20
  %266 = bitcast i8* %pBuff to i32*
  %267 = getelementptr i32, i32* %266, i32 %265
  %268 = load i32, i32* %267, align 4
  store i32 %268, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %269 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %270 = add i32 %269, -44
  %271 = bitcast i8* %pBuff to i32*
  %272 = getelementptr i32, i32* %271, i32 %270
  %273 = load i32, i32* %272, align 4
  store i32 %273, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %274 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %275 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %276 = icmp sge i32 %274, %275
  br i1 %276, label %BB1, label %BB12

BB12:                                             ; preds = %BB11
  %277 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %278 = add i32 %277, 0
  %279 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %280 = add i32 %279, 0
  store i32 %280, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %281 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %282 = add i32 %281, 60
  %283 = bitcast i8* %pBuff to i32*
  %284 = getelementptr i32, i32* %283, i32 %282
  %285 = load i32, i32* %284, align 4
  store i32 %285, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %286 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %287 = add i32 %286, 56
  %288 = bitcast i8* %pBuff to i32*
  %289 = getelementptr i32, i32* %288, i32 %287
  %290 = load i32, i32* %289, align 4
  store i32 %290, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %291 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %292 = add i32 %291, 52
  %293 = bitcast i8* %pBuff to i32*
  %294 = getelementptr i32, i32* %293, i32 %292
  %295 = load i32, i32* %294, align 4
  store i32 %295, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 9), align 4
  %296 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %297 = add i32 %296, 64
  store i32 %297, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %298 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  ret void
}

define void @Func.6(i8* %pBuff) {
BB:
  %0 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %1 = add i32 %0, -448
  store i32 %1, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %2 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %3 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %4 = bitcast i8* %pBuff to i32*
  %5 = add i32 %2, 444
  %6 = getelementptr i32, i32* %4, i32 %5
  store i32 %3, i32* %6, align 4
  %7 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %8 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %9 = bitcast i8* %pBuff to i32*
  %10 = add i32 %7, 440
  %11 = getelementptr i32, i32* %9, i32 %10
  store i32 %8, i32* %11, align 4
  %12 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %13 = add i32 %12, 448
  store i32 %13, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %14 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %15 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %16 = bitcast i8* %pBuff to i32*
  %17 = add i32 %14, -436
  %18 = getelementptr i32, i32* %16, i32 %17
  store i32 %15, i32* %18, align 4
  %19 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %20 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %21 = bitcast i8* %pBuff to i32*
  %22 = add i32 %19, -440
  %23 = getelementptr i32, i32* %21, i32 %22
  store i32 %20, i32* %23, align 4
  %24 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %25 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 12), align 4
  %26 = bitcast i8* %pBuff to i32*
  %27 = add i32 %24, -444
  %28 = getelementptr i32, i32* %26, i32 %27
  store i32 %25, i32* %28, align 4
  %29 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %30 = add i32 %29, -444
  %31 = bitcast i8* %pBuff to i32*
  %32 = getelementptr i32, i32* %31, i32 %30
  %33 = load i32, i32* %32, align 4
  store i32 %33, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 12), align 4
  %34 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %35 = add i32 %34, -440
  %36 = bitcast i8* %pBuff to i32*
  %37 = getelementptr i32, i32* %36, i32 %35
  %38 = load i32, i32* %37, align 4
  store i32 %38, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %39 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %40 = add i32 %39, -436
  %41 = bitcast i8* %pBuff to i32*
  %42 = getelementptr i32, i32* %41, i32 %40
  %43 = load i32, i32* %42, align 4
  store i32 %43, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  call void @Func.3(i8* %pBuff)
  store i32 66640, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %44 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %45 = add i32 %44, 0
  store i32 %45, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %46 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %47 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %48 = icmp eq i32 %46, %47
  br i1 %48, label %BB2, label %BB1

BB1:                                              ; preds = %BB
  %49 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %50 = add i32 %49, -444
  %51 = bitcast i8* %pBuff to i32*
  %52 = getelementptr i32, i32* %51, i32 %50
  %53 = load i32, i32* %52, align 4
  store i32 %53, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 12), align 4
  %54 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %55 = add i32 %54, -440
  %56 = bitcast i8* %pBuff to i32*
  %57 = getelementptr i32, i32* %56, i32 %55
  %58 = load i32, i32* %57, align 4
  store i32 %58, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %59 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %60 = add i32 %59, -436
  %61 = bitcast i8* %pBuff to i32*
  %62 = getelementptr i32, i32* %61, i32 %60
  %63 = load i32, i32* %62, align 4
  store i32 %63, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  call void @Func.4(i8* %pBuff)
  store i32 66664, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  br label %BB5

BB2:                                              ; preds = %BB
  %64 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %65 = add i32 %64, -440
  %66 = bitcast i8* %pBuff to i32*
  %67 = getelementptr i32, i32* %66, i32 %65
  %68 = load i32, i32* %67, align 4
  store i32 %68, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %69 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %70 = add i32 %69, 1
  store i32 %70, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %71 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %72 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %73 = bitcast i8* %pBuff to i32*
  %74 = add i32 %71, -440
  %75 = getelementptr i32, i32* %73, i32 %74
  store i32 %72, i32* %75, align 4
  %76 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %77 = add i32 %76, -424
  store i32 %77, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %78 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %79 = add i32 %78, -420
  store i32 %79, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %80 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %81 = add i32 %80, 0
  store i32 %81, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 13), align 4
  %82 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %83 = add i32 %82, -444
  %84 = bitcast i8* %pBuff to i32*
  %85 = getelementptr i32, i32* %84, i32 %83
  %86 = load i32, i32* %85, align 4
  store i32 %86, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 12), align 4
  %87 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %88 = add i32 %87, -440
  %89 = bitcast i8* %pBuff to i32*
  %90 = getelementptr i32, i32* %89, i32 %88
  %91 = load i32, i32* %90, align 4
  store i32 %91, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %92 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %93 = add i32 %92, -436
  %94 = bitcast i8* %pBuff to i32*
  %95 = getelementptr i32, i32* %94, i32 %93
  %96 = load i32, i32* %95, align 4
  store i32 %96, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  call void @Func.5(i8* %pBuff)
  store i32 66708, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %97 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %98 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %99 = bitcast i8* %pBuff to i32*
  %100 = add i32 %97, -20
  %101 = getelementptr i32, i32* %99, i32 %100
  store i32 %98, i32* %101, align 4
  br label %BB4

BB3:                                              ; preds = %BB4
  %102 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %103 = add i32 %102, -440
  %104 = bitcast i8* %pBuff to i32*
  %105 = getelementptr i32, i32* %104, i32 %103
  %106 = load i32, i32* %105, align 4
  store i32 %106, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %107 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %108 = shl i32 %107, 2
  store i32 %108, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %109 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %110 = add i32 %109, -436
  %111 = bitcast i8* %pBuff to i32*
  %112 = getelementptr i32, i32* %111, i32 %110
  %113 = load i32, i32* %112, align 4
  store i32 %113, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %114 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %115 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %116 = add i32 %114, %115
  store i32 %116, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %117 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %118 = add i32 %117, -20
  %119 = bitcast i8* %pBuff to i32*
  %120 = getelementptr i32, i32* %119, i32 %118
  %121 = load i32, i32* %120, align 4
  store i32 %121, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %122 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %123 = shl i32 %122, 2
  store i32 %123, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %124 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %125 = add i32 %124, -16
  store i32 %125, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 13), align 4
  %126 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 13), align 4
  %127 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %128 = add i32 %126, %127
  store i32 %128, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %129 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %130 = add i32 %129, -404
  %131 = bitcast i8* %pBuff to i32*
  %132 = getelementptr i32, i32* %131, i32 %130
  %133 = load i32, i32* %132, align 4
  store i32 %133, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %134 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %135 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %136 = bitcast i8* %pBuff to i32*
  %137 = add i32 %134, 0
  %138 = getelementptr i32, i32* %136, i32 %137
  store i32 %135, i32* %138, align 4
  %139 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %140 = add i32 %139, -444
  %141 = bitcast i8* %pBuff to i32*
  %142 = getelementptr i32, i32* %141, i32 %140
  %143 = load i32, i32* %142, align 4
  store i32 %143, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 12), align 4
  %144 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %145 = add i32 %144, -440
  %146 = bitcast i8* %pBuff to i32*
  %147 = getelementptr i32, i32* %146, i32 %145
  %148 = load i32, i32* %147, align 4
  store i32 %148, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 11), align 4
  %149 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %150 = add i32 %149, -436
  %151 = bitcast i8* %pBuff to i32*
  %152 = getelementptr i32, i32* %151, i32 %150
  %153 = load i32, i32* %152, align 4
  store i32 %153, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  call void @Func.6(i8* %pBuff)
  store i32 66772, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %154 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %155 = add i32 %154, -20
  %156 = bitcast i8* %pBuff to i32*
  %157 = getelementptr i32, i32* %156, i32 %155
  %158 = load i32, i32* %157, align 4
  store i32 %158, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %159 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %160 = add i32 %159, 1
  store i32 %160, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %161 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %162 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %163 = bitcast i8* %pBuff to i32*
  %164 = add i32 %161, -20
  %165 = getelementptr i32, i32* %163, i32 %164
  store i32 %162, i32* %165, align 4
  br label %BB4

BB4:                                              ; preds = %BB3, %BB2
  %166 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %167 = add i32 %166, -424
  %168 = bitcast i8* %pBuff to i32*
  %169 = getelementptr i32, i32* %168, i32 %167
  %170 = load i32, i32* %169, align 4
  store i32 %170, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %171 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %172 = add i32 %171, -20
  %173 = bitcast i8* %pBuff to i32*
  %174 = getelementptr i32, i32* %173, i32 %172
  %175 = load i32, i32* %174, align 4
  store i32 %175, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %176 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 14), align 4
  %177 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %178 = icmp slt i32 %176, %177
  br i1 %178, label %BB3, label %BB5

BB5:                                              ; preds = %BB4, %BB1
  %179 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %180 = add i32 %179, 0
  %181 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %182 = add i32 %181, 444
  %183 = bitcast i8* %pBuff to i32*
  %184 = getelementptr i32, i32* %183, i32 %182
  %185 = load i32, i32* %184, align 4
  store i32 %185, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  %186 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %187 = add i32 %186, 440
  %188 = bitcast i8* %pBuff to i32*
  %189 = getelementptr i32, i32* %188, i32 %187
  %190 = load i32, i32* %189, align 4
  store i32 %190, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %191 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %192 = add i32 %191, 448
  store i32 %192, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %193 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  ret void
}

define void @Func.7(i8* %pBuff) {
BB:
  %0 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %1 = add i32 %0, -32
  store i32 %1, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %2 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %3 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %4 = bitcast i8* %pBuff to i32*
  %5 = add i32 %2, 28
  %6 = getelementptr i32, i32* %4, i32 %5
  store i32 %3, i32* %6, align 4
  %7 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %8 = add i32 %7, 32
  store i32 %8, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %9 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %10 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %11 = bitcast i8* %pBuff to i32*
  %12 = add i32 %9, -20
  %13 = getelementptr i32, i32* %11, i32 %12
  store i32 %10, i32* %13, align 4
  %14 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %15 = add i32 %14, -20
  %16 = bitcast i8* %pBuff to i32*
  %17 = getelementptr i32, i32* %16, i32 %15
  %18 = load i32, i32* %17, align 4
  store i32 %18, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %19 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %20 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %21 = icmp sge i32 %19, %20
  br i1 %21, label %BB2, label %BB1

BB1:                                              ; preds = %BB
  %22 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %23 = add i32 %22, -20
  %24 = bitcast i8* %pBuff to i32*
  %25 = getelementptr i32, i32* %24, i32 %23
  %26 = load i32, i32* %25, align 4
  store i32 %26, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %27 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 0), align 4
  %28 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %29 = sub i32 %27, %28
  store i32 %29, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  br label %BB3

BB2:                                              ; preds = %BB
  %30 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %31 = add i32 %30, -20
  %32 = bitcast i8* %pBuff to i32*
  %33 = getelementptr i32, i32* %32, i32 %31
  %34 = load i32, i32* %33, align 4
  store i32 %34, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  br label %BB3

BB3:                                              ; preds = %BB2, %BB1
  %35 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 15), align 4
  %36 = add i32 %35, 0
  store i32 %36, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 10), align 4
  %37 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %38 = add i32 %37, 28
  %39 = bitcast i8* %pBuff to i32*
  %40 = getelementptr i32, i32* %39, i32 %38
  %41 = load i32, i32* %40, align 4
  store i32 %41, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 8), align 4
  %42 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %43 = add i32 %42, 32
  store i32 %43, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 2), align 4
  %44 = load i32, i32* getelementptr inbounds ([32 x i32], [32 x i32]* @RegFile, i32 0, i32 1), align 4
  ret void
}

define void @Func.8(i8* %pBuff) {
BB:
  call void @llvm.debugtrap()
  ret void
}

; Function Attrs: nounwind
declare void @llvm.debugtrap() #0

attributes #0 = { nounwind }
