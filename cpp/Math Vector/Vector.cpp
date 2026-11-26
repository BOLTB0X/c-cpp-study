#include <algorithm>
#include <cmath>
#include <iostream>

struct Vector3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    float Length() const {
        return std::sqrt(
            x * x +
            y * y +
            z * z
        );
    }
};

Vector3 Normalize(Vector3 v) {
    float length = v.Length();

    if (length == 0.0f) return { 0.0f, 0.0f, 0.0f };

    return {
        v.x / length,
        v.y / length,
        v.z / length
    };
}

// 일반 내적: a.x * b.x + a.y * b.y + a.z * b.z
float Dot(const Vector3& a, const Vector3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// 정규화(단위 벡터) 후 내적: cos(theta) 근사
float DotNormalized(const Vector3& a, const Vector3& b) {
    Vector3 na = Normalize(a);
    Vector3 nb = Normalize(b);
    return Dot(na, nb);
}

// 사이각(라디안) 계산: 부동소수점 오차 방지를 위해 [-1.0f, 1.0f]로 clamp
float AngleRadians(const Vector3& a, const Vector3& b) {
    float lenA = a.Length();
    float lenB = b.Length();
    if (lenA == 0.0f || lenB == 0.0f) return 0.0f;

    float cosTheta = Dot(a, b) / (lenA * lenB);
    cosTheta = std::clamp(cosTheta, -1.0f, 1.0f);
    return std::acos(cosTheta);
}

int main() {
    Vector3 a{ 2.0f, 0.0f, 0.0f };
    Vector3 b{ 0.0f, 3.0f, 0.0f };
    Vector3 c{ 4.0f, 0.0f, 0.0f };

    std::cout << "Dot(a, b) [수직]: " << Dot(a, b) << '\n';
    std::cout << "Dot(a, c) [같은 방향]: " << Dot(a, c) << '\n';
    std::cout << "DotNormalized(a, c) [단위 벡터 내적]: " << DotNormalized(a, c) << '\n';

    float rad = AngleRadians(a, b);
    constexpr float kRadToDeg = 180.0f / 3.14159265358979323846f;
    std::cout << "Angle(a, b) [deg]: " << rad * kRadToDeg << '\n';

    return 0;
}