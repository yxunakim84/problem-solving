import unittest
# 실제 solution 함수가 있는 파일을 임포트합니다.
# 예를 들어, solution.py에 solution 함수가 있다면
from solution import solution

class TestMemoryScore(unittest.TestCase):
    """
    '추억 점수' 문제에 대한 테스트 케이스 클래스
    """

    def test_case_1(self):
        """
        입출력 예 #1 테스트
        """
        name = ["may", "kein", "kain", "radi"]
        yearning = [5, 10, 1, 3]
        photo = [
            ["may", "kein", "kain", "radi"],
            ["may", "kein", "brin", "deny"],
            ["kon", "kain", "may", "coni"]
        ]
        expected_result = [19, 15, 6]
        self.assertEqual(solution(name, yearning, photo), expected_result, "Test Case 1 Failed")

    def test_case_2(self):
        """
        입출력 예 #2 테스트
        """
        name = ["kali", "mari", "don"]
        yearning = [11, 1, 55]
        photo = [
            ["kali", "mari", "don"],
            ["pony", "tom", "teddy"],
            ["con", "mona", "don"]
        ]
        expected_result = [67, 0, 55]
        self.assertEqual(solution(name, yearning, photo), expected_result, "Test Case 2 Failed")

    def test_case_3(self):
        """
        입출력 예 #3 테스트
        """
        name = ["may", "kein", "kain", "radi"]
        yearning = [5, 10, 1, 3]
        photo = [
            ["may"],
            ["kein", "deny", "may"],
            ["kon", "coni"]
        ]
        expected_result = [5, 15, 0]
        self.assertEqual(solution(name, yearning, photo), expected_result, "Test Case 3 Failed")

    def test_empty_photo(self):
        """
        빈 사진 (photo[i]의 길이가 0)이 주어졌을 때 테스트 (제한사항에 1 이상 명시되어 있으나, 확장성을 위해)
        """
        name = ["a"]
        yearning = [10]
        photo = [[""], ["b"]] # 비어있거나, 매핑되지 않는 이름만 있을 때
        expected_result = [0, 0]
        self.assertEqual(solution(name, yearning, photo), expected_result, "Test Empty Photo Failed")

    def test_no_matching_names(self):
        """
        사진 속 모든 인물이 그리움 점수에 없는 경우
        """
        name = ["may"]
        yearning = [5]
        photo = [["kein", "kain"], ["radi"]]
        expected_result = [0, 0]
        self.assertEqual(solution(name, yearning, photo), expected_result, "Test No Matching Names Failed")

    def test_single_person_multiple_times_in_photo(self):
        """
        한 사진에 동일 인물이 여러 번 등장하는 경우 (제한사항에 중복 없다고 명시되어 있으나 확인용)
        """
        name = ["may"]
        yearning = [5]
        photo = [["may", "may", "may"]] # 실제 문제 제한사항에는 photo[i] 원소 중복 없다고 명시됨.
        expected_result = [15] # 5+5+5
        self.assertEqual(solution(name, yearning, photo), expected_result, "Test Single Person Multiple Times Failed")


if __name__ == '__main__':
    # 이 파일을 직접 실행하면 테스트가 진행됩니다.
    unittest.main()